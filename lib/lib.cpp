#include <vector>

namespace lib{
    
class SegmentTree {
private: 
    vi st, A;
    int n;
    int left (int p) { return p << 1; }
    int right (int p) { return (p << 1) + 1;}
    void build(int p, int L, int R) { //O(n)
        if(L == R){
            st[p] = L;
        } else {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    int rmqPri(int p, int L, int R, int i, int j){ //O(log n)
        if(i>R || j < L) { return -1; }
        if(L >= i && R <= j) { return st[p]; }

        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
public: 
    SegmentTree(const vi &_A) {
        A = _A; 
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1,0, n-1);
    }
    int rmq(int i, int j){
        return rmqPri(1, 0, n-1, i, j);
    }
};


class FenwickTree {
private: 
    vi ft;
    int LSOne(int i) { return (i & (-i)); }
public: 
    FenwickTree(int n){ ft.assign(n+1,0); }
    int rsq(int b) {
        int sum = 0; 
        for(; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    int rsq(int a, int b) {
        return rsq(b) - (a ==1 ? 0 : rsq(a-1));
    }
    void adjust(int k, int v){
        for(; k< (int) ft.size(); k+=LSOne(k)) {
            ft[k] += v;
        }
    }
};

class DSU {
private: vi p, rank;
public:
    DSU(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i=0; i<N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
    
};

}