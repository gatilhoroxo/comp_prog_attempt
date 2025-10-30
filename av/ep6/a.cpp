//counting rooms
//grafo bidirecional
//bfs
//contagem de componentes conexos '.' separados entre '#'
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define VISITED 1
#define UNVISITED 0


struct GraphUtils {
    vector<vector<vii>> adjList;
    vector<string> vts;
    int r, c;

    GraphUtils(vector<vector<vii>> al, vector<string>vts_, int r_, int c_)
        : adjList(al), vts(vts_), r(r_), c(c_) {}

    void dfs_list(vvi& vt, int u, int v){
        vt[u][v] = VISITED;
        for(auto p: adjList[u][v]){
            int i = p.first, j = p.second; 
            if(vt[i][j] == UNVISITED && vts[i][j] == '.') 
                dfs_list(vt, i, j);
        }
    }

    int call(){
        vvi vis(r, vi(c, UNVISITED));
        int cnx=0;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(vis[i][j] == UNVISITED && vts[i][j] == '.'){
                    dfs_list(vis, i, j);
                    cnx++;
                }
            }
        }
        return cnx;
    }

    // void bfs(vi& vt, int start){
    //     queue<int> q;
    //     q.push(start);
    //     vt[start] = VISITED;
    //     while(!q.empty()){
    //         int v = q.front(); q.pop();
    //         for(auto &w: adjList[v]){
    //             if(vt[w] == UNVISITED){
    //                 vt[w] = VISITED;
    //                 q.push(w);
    //             }
    //         }
    //     }
    // }
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    int r, c; cin >> r >> c;

    vector<string> vt(r);
    vector<vector<vii>> adj(r,vector<vii>(c));
    for(int i=0; i< r; i++){
        cin >> vt[i];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(vt[i][j] == '.'){
                if(i+1<r) adj[i][j].push_back({i+1, j});
                if(j+1<c) adj[i][j].push_back({i, j+1});
                if(i-1 >= 0) adj[i][j].push_back({i-1, j});
                if(j-1 >= 0) adj[i][j].push_back({i, j-1});
            }
        }
    }

    GraphUtils grafo(adj, vt, r, c);
    cout << grafo.call() << '\n';
    

    }

    return 0;
}

