//road construction
//nao entendi o problema
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
//#define ll long long

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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;  
    cin >> n >> m;
    vector<int> vt(n);
    for(int i=0; i<n; i++) vt[i] = i+1;
    
    
    while(m--){
        int a, b;
        cin >> a >> b;
        int numComp, sizeCompGG;

    }

    return 0;
}