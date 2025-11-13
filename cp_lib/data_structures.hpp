#ifndef DATA_STRUCTURES_HPP
#define DATA_STRUCTURES_HPP

#include "cp_lib.hpp"

// ==================== Segment Tree (RMQ) ====================
// Uso: consultar mínimo em intervalo O(log n), modificar O(log n)
class SegmentTree {
private: 
    vi st, A;
    int n;
    
    int left(int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }
    
    void build(int p, int L, int R) {
        if(L == R) {
            st[p] = L;
        } else {
            build(left(p), L, (L+R)/2);
            build(right(p), (L+R)/2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2;
        }
    }
    
    int _rmq(int p, int L, int R, int i, int j) {
        if(i > R || j < L) return -1;
        if(L >= i && R <= j) return st[p];
        
        int p1 = _rmq(left(p), L, (L+R)/2, i, j);
        int p2 = _rmq(right(p), (L+R)/2 + 1, R, i, j);
        
        if(p1 == -1) return p2;
        if(p2 == -1) return p1;
        return (A[p1] <= A[p2]) ? p1 : p2;
    }
    
    void _modify(int p, int L, int R, int idx, int val) {
        if(L == R) {
            A[idx] = val;
            st[p] = L;
        } else {
            int mid = (L + R) / 2;
            if(idx <= mid) _modify(left(p), L, mid, idx, val);
            else _modify(right(p), mid+1, R, idx, val);
            
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] <= A[p2]) ? p1 : p2; 
        }
    }
    
    int _sum_query(int p, int L, int R, int i, int j) {
        if(L >= i && R <= j) return A[st[p]];
        
        int p1 = _sum_query(left(p), L, (L+R)/2, i, j);
        int p2 = _sum_query(right(p), (L+R)/2+1, R, i, j);
        return A[p1] + A[p2];
    }

public: 
    SegmentTree(const vi &_A) {
        A = _A; 
        n = (int)A.size();
        st.assign(4 * n, 0);
        build(1, 0, n-1);
    }
    
    // Retorna o valor mínimo no intervalo [i, j] (1-indexed)
    int rmq(int i, int j) {
        return A[_rmq(1, 0, n-1, i-1, j-1)];
    }
    
    // Modifica o valor na posição idx (1-indexed)
    void modify(int idx, int val) {
        _modify(1, 0, n-1, idx-1, val);
    }
    
    // Consulta soma no intervalo [i, j] (1-indexed)
    int sum_query(int i, int j) {
        return _sum_query(1, 0, n-1, i-1, j-1);
    }
    
    void print_tree() {
        for(auto &i : A) cout << i << ' ';
        cout << '\n';
        for(int i = 1; i <= n; i++) cout << st[i] << ' ';
        cout << '\n';
    }
};


// ==================== Fenwick Tree (BIT) ====================
// Uso: Range Sum Query (RSQ) e atualizações pontuais O(log n)
class FenwickTree {
private: 
    vi ft;
    int LSOne(int i) { return (i & (-i)); }
    
public: 
    FenwickTree(int n) { ft.assign(n+1, 0); }
    
    // Retorna soma [1..b]
    int rsq(int b) {
        int sum = 0; 
        for(; b; b -= LSOne(b)) sum += ft[b];
        return sum;
    }
    
    // Retorna soma [a..b]
    int rsq(int a, int b) {
        return rsq(b) - (a == 1 ? 0 : rsq(a-1));
    }
    
    // Adiciona v ao índice k
    void adjust(int k, int v) {
        for(; k < (int)ft.size(); k += LSOne(k)) {
            ft[k] += v;
        }
    }
};


// ==================== Union-Find / Disjoint Set Union ====================
// Uso: verificar conectividade e unir conjuntos O(α(n)) ~ O(1)
class UnionFind {
private: 
    vi p, rank;
    
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) {
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
        if(!isSameSet(i, j)) {
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

// Alias para usar DSU como nome alternativo
using DSU = UnionFind;

#endif // DATA_STRUCTURES_HPP
