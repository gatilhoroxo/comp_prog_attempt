//dynamic range sum queries
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

 
class SegmentTree {
private: 
    vector<long long> stsum;
    vi stmin, A;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1;}
    void buildmin(int p, int L, int R) { //O(n)
        if(L == R){
            stmin[p] = L;
        } else {
            buildmin(left(p), L, (L+R)/2);
            buildmin(right(p), (L+R)/2 + 1, R);
            int p1 = stmin[left(p)], p2 = stmin[right(p)];
            stmin[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }    
    int rmqPri(int p, int L, int R, int i, int j){ //O(log n)
        if(i>R || j < L) { return -1; }
        if(L >= i && R <= j) { return stmin[p]; }

        int p1 = rmqPri(left(p), L, (L+R)/2, i, j);
        int p2 = rmqPri(right(p), (L+R)/2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void buildsum(int p, int L, int R){
        if(L == R){ stsum[p] = A[L]; }
        else {
            buildsum(left(p), L, (L+R)/2);
            buildsum(right(p), (L+R)/2 +1, R);
            stsum[p] = stsum[left(p)] + stsum[right(p)];
        }
    }
    long long _rsq(int p, int L, int R, int& i, int& j){
        if (i > R || j<L) return 0;
        if(L>=i && R <=j) return stsum[p];
        long long p1 = _rsq(left(p), L, (L+R)/2, i, j);
        long long p2 = _rsq(right(p), (L+R)/2 + 1, R, i, j);
        return p1 + p2;
    }
    void _updatesum(int p, int L, int R, int& idx, int& up){
        if (L==R) {
            A[idx] = up;
            stsum[p] = up;
        } else {
            int m = (L+R)/2;
            if (idx <= m) _updatesum(left(p), L, m, idx, up);
            else _updatesum(right(p), m+1, R, idx, up);
            stsum[p] = stsum[left(p)] + stsum[right(p)];
        }
    }
public: 
    SegmentTree(const vi &_A) {
        A = _A; 
        n = (int)A.size();
        stsum.assign(4 * n, 0);
        //buildmin(1,0, n-1);
        buildsum(1, 0, n-1);
    }
    int rmq(int i, int j){
        return rmqPri(1, 0, n-1, i, j);
    }
    void updatesum(int idx, int up){
        _updatesum(1, 0, n-1, --idx, up) ;
    }
    long long rsq(int i, int j){
        return _rsq(1, 0, n-1, --i, --j);
    }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q; 
    vector<int> vt(n);
    for(auto &i: vt) cin >> i;
    SegmentTree st(vt);
    while(q--){
        int query, a, b;
        cin >> query >> a >> b;
        if(query == 1) st.updatesum(a, b);
        else cout << st.rsq(a, b) << '\n';
    }

    return 0;
}