//counting rooms
#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int,int>;
using vii = vector<ii>;

#define VISITED 1
#define UNVISITED 0

struct GraphUtils {
    vector<vector<vii>> adj;
    vector<string> vts;
    int r, c;

    GraphUtils(vector<vector<vii>> al, vector<string>vts_, int r_, int c_)
        : adj(al), vts(vts_), r(r_), c(c_) {}

    void dfs_list(vvi& vt, int u, int v){
        vt[u][v] = VISITED;
        for(auto p: adj[u][v]){
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

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; 
    cin >> n >> m;
    vector<string> vt(n);
    vector<vector<vii>> adj(n,vector<vii>(m));
    for(auto&s:vt) cin >> s;

    //graph
    for(int i=0; i<n; i++){
        int tam = vt[i].size();
        for(int j=0; j<vt[i].size(); j++){
            if(vt[i][j] == '.'){
                if((i+1)<n) if(vt[i+1][j] == '.')
                    {adj[i][j].push_back({i+1,j});}
                if((i-1)>=0) if(vt[i-1][j] == '.')
                    {adj[i][j].push_back({i-1,j});}
                if((j+1)<tam) if(vt[i][j+1] == '.')
                    {adj[i][j].push_back({i,j+1});}
                if((j-1)>=0) if(vt[i][j-1] == '.')
                    {adj[i][j].push_back({i,j-1});}
            }
        }
    }

    //dfs
    GraphUtils grafo(adj, vt,n,m);
    cout << grafo.call() << '\n';

    return 0;
}

