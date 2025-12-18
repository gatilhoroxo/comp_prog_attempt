//driving range
//minmax (mst)
//grafo bidirecional
//qual a maior aresta no caminho de uma cidade para outra
#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;


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

bool cmp(pair<int, ii> a, pair<int, ii> b){
    return (a.first < b.first);
}

struct mst{
    vector<pair<int, ii>> edgelist;
    int e, n;
    priority_queue<ii> pq;
    mst(vector<pair<int, ii>> edgelist_, int n_) 
      : edgelist(edgelist_), e(edgelist_.size()), n(n_) {
    }

    int kruskal(){
        int maximo = 0;
        UnionFind uf(n);
        for(int i=0; i<edgelist.size(); i++){
            pair<int, ii> front = edgelist[i];
            if(!uf.isSameSet(front.second.first, front.second.second)) {
                maximo = max(maximo, front.first);
                uf.unionSet(front.second.first, front.second.second);
            }
        }
        return maximo;
    }

    int call_mst_k(){
        sort(edgelist.begin(), edgelist.end(), cmp);
        return kruskal();
    }
    
};

struct GraphUtils {
    vvi adjList;   
    int n = 0;

    GraphUtils(const vvi& al): adjList(al), n(al.size()) {}

    void dfs_list(vi& vt, int u){
        vt[u] = VISITED;
        for(auto j: adjList[u]){
            if(vt[j] == UNVISITED) 
                dfs_list(vt, j);
        }
    }

    int conected_comp(){
        vi vt(n, UNVISITED);
        int cities=0;
        for(int i=0; i<n; i++){
            if(vt[i] == UNVISITED){
                dfs_list(vt, i);
                cities++;
            }
        }

        return cities;
    }

};

//=====================================================================

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    int n,m; 
    while((cin >> n >> m)){
        if(n == 0 && m == 0) break;
        vector<pair<int, ii>> edges(m);
        vvi adj(n);
        for(int i=0; i<m; i++){
            int city1, city2, range;
            cin >> city1 >> city2 >> range;

            edges.push_back({range, {city1,city2}});

            adj[city1].push_back(city2);
            adj[city2].push_back(city1);
        }

        GraphUtils grafoconexo(adj);
        int cnx = grafoconexo.conected_comp();
        if(cnx == 1) {
            mst tree(edges, n);
            cout << tree.call_mst_k() << "\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }

    }

    return 0;
}
