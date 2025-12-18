//DZY Loves Chemistry
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 

class UnionFind {
private: 
    vi p, rank;
    int numSets;
    
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        numSets = N; 
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
            numSets--;
        }
    }
    
    int countSets() {
        return numSets;
    }
};

using DSU = UnionFind;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    DSU dsu(n + 1);
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unionSet(x, y);
    }
    
    int components = 0;
    for(int i = 1; i <= n; i++) {
        if(dsu.findSet(i) == i) {
            components++;
        }
    }
    
    long long danger = 1LL << (n - components); 
    cout << danger << '\n';

    return 0;
}