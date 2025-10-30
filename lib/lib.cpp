#include <vector>
#include <iostream>
using namespace std;
#define vi vector<int>

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
    int _rmq(int p, int L, int R, int i, int j){ //O(log n)
        if(i>R || j < L) { return -1; }
        if(L >= i && R <= j) { return st[p]; }

        int p1 = _rmq(left(p), L, (L+R)/2, i, j);
        int p2 = _rmq(right(p), (L+R)/2 + 1, R, i, j);
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
    void _modify(int p, int L, int R, int idx, int up){
        if(L == R) {
            A[idx] = up;
            st[p] = L;
        } else {
            int meio = (L + R) / 2;
            if(idx <= meio) _modify(left(p), L, meio, idx, up);
            else _modify(right(p), meio+1, R, idx, up);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2; 
        }
    }
    int _sq(int p, int L, int R, int i, int j){
        if(L >= i && R <= j) { return A[st[p]];}

        int p1 = _sq(left(p), L, (L+R)/2, i, j);
        int p2 = _sq(right(p), (L+R)/2+1, R, i, j);
        return A[p1] + A[p2];
    }

public: 
    SegmentTree(const vi &_A) {
        A = _A; 
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1,0, n-1);
    }
    void modify(int idx, int up){
        _modify(1, 0, n-1, idx-1, up);
    }
    int rmq(int i, int j){
        return A[_rmq(1, 0, n-1, i-1, j-1)];
    }
    void printtree(){
        for(auto &i:A){ cout << i << ' ';}
        cout << '\n';
        for(int i=1; i<=A.size(); i++) { 
            cout << st[i] << ' ';
        }
        cout << '\n';
    }
    int sq(int i, int j){
        return _sq(1, 0, n-1, i-1, j-1);
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