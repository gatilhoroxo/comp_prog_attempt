#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

 
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

        int p1 = rmqPri(left(p), L, (L+R)/2, i, j);
        int p2 = rmqPri(right(p), (L+R)/2 + 1, R, i, j);
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


int main() {
    srand(time(0));
    cout << "=== TESTES ===" << endl;

    // --- Segment Tree ---
    cout << "\n[Segment Tree]" << endl;
    vector<int> arr(10);
    for (int &x : arr) x = rand() % 100;
    for (int &x : arr) cout << x << ' ';
    cout << '\n';
    SegmentTree st(arr);
    bool ok = true;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            int idx = st.rmq(i, j);
            int bruteIdx = i;
            for (int k = i; k <= j; k++)
                if (arr[k] < arr[bruteIdx]) bruteIdx = k;
            if (arr[idx] != arr[bruteIdx]) ok = false;
        }
    }
    cout << (ok ? "SegmentTree OK!" : "SegmentTree ERRO!") << endl;

    // --- Fenwick Tree ---
    cout << "\n[Fenwick Tree]" << endl;
    FenwickTree ft(10);
    vector<int> farr(11, 0);
    for (int i = 1; i <= 10; i++) {
        int val = rand() % 10;
        ft.adjust(i, val);
        farr[i] = val;
    }

    ok = true;
    for (int i = 1; i <= 10; i++) {
        int brute = 0;
        for (int k = 1; k <= i; k++) brute += farr[k];
        if (ft.rsq(i) != brute) ok = false;
    }
    cout << (ok ? "FenwickTree OK!" : "FenwickTree ERRO!") << endl;

    // --- Union-Find ---
    cout << "\n[Union-Find]" << endl;
    DSU uf(10);
    uf.unionSet(1, 2);
    uf.unionSet(2, 3);
    uf.unionSet(4, 5);
    bool cond1 = uf.isSameSet(1, 3);
    bool cond2 = !uf.isSameSet(1, 4);
    cout << ((cond1 && cond2) ? "UnionFind OK!" : "UnionFind ERRO!") << endl;

    cout << "\n=== FIM DOS TESTES ===" << endl;
}
