//road reparation
//
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;
using iii = pair<ll,ii>;
using vi = vector<ll>;

//reparacao das vias com o menor custo possivel

#define VISITED 1
#define UNVISITED 0

class UnionFind {
private: vi p, rank;
public:
    UnionFind(int N) {
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

bool cmp(iii a, iii b){
    return (a.first < b.first);
}

class mst{
private:
    vector<iii> edgelist;
    ll e, n;
    vi taken;
    priority_queue<ii> pq;
public:
    mst(vector<iii> edgelist_, int n_) : edgelist(edgelist_), e(edgelist_.size()), n(n_) {}

    ii kruskal(){
        ll cost=0;
        int edges_used = 0;
        UnionFind uf(n);
        for(int i=0; i<edgelist.size(); i++){
            iii front = edgelist[i];
            if(!uf.isSameSet(front.second.first, front.second.second)) {
                cost += front.first;
                edges_used++;
                uf.unionSet(front.second.first, front.second.second);
            }
        }
        return {edges_used, cost};
    }

    ii call_mst_k(){
        taken.assign(n, UNVISITED);
        sort(edgelist.begin(), edgelist.end(), cmp);
        return kruskal();
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m; 
    vector<iii> vt;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vt.push_back({c,{a-1,b-1}});
        vt.push_back({c,{b-1,a-1}});
    }

    mst tree(vt, n);
    ii par = tree.call_mst_k();

    if(par.first < n-1) cout <<  "IMPOSSIBLE\n";
    else cout << par.second << '\n';

    return 0;
}
