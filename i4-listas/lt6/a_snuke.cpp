//snuke maze
//aceito
#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using viii = vector<pair<int,ii>>;
using vviii = vector<viii>;

string snuke = "snuke";

#define VISITED 1
#define UNVISITED 0

struct GraphUtils {
    vector<vviii> adjPairs;
    vector<string> vts;
    int n = 0;
    int r=0,c=0;

    GraphUtils(vector<vviii> adj_, vector<string> a_, int r_, int c_) : adjPairs(adj_), vts(a_), r(r_), c(c_) {}

    bool dfs_pairs(vvi& vt, int u, int v){
        if(u == vt.size()-1 && v == vt[u].size()-1) return true;
        bool path = false;
        vt[u][v] = VISITED;
        for(auto&j:adjPairs[u][v]){
            int seg = j.first;
            int idx = j.second.first;
            int jdx = j.second.second;
            if(vt[idx][jdx] == UNVISITED && vts[idx][jdx] == snuke[seg]) {
                path = path || dfs_pairs(vt, idx, jdx);
            }
        }
        return path;
    }

    bool call(){
        vvi vis(r, vi(c, UNVISITED));
        //rever como verificar
        return dfs_pairs(vis, 0, 0);
    }

};

void printEdges(vector<vviii> &adj, vector<string> &vt){
    cout << "Listas de arestas:\n";
    for(int i=0; i<adj.size(); i++){
        for(int j=0;j<adj[i].size();j++){
            cout <<'(' << i << ' ' << j << "):" << vt[i][j] << "\n\t";
            for(auto&k:adj[i][j]){
                int seg=k.first;
                int m=k.second.first;
                int n=k.second.second;
                if(vt[m][n] == snuke[seg])
                    cout <<'(' << m << ' ' << n << ')' << "[" << vt[m][n] <<"]";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int r, c; cin >> r >> c;
    vector<string> vts(r);
    vector<vviii> adj(r,vviii(c));
    for(int i=0; i<r; i++){
        cin >> vts[i]; //input
        //processando arestas
        for(int j=0; j<c; j++){
            int seg = 0;
            if(vts[i][j] == 's') seg = 1;
            else if(vts[i][j] == 'n') seg = 2;
            else if(vts[i][j] == 'u') seg = 3;
            else if(vts[i][j] == 'k') seg = 4;
            else seg = 0;

            if(i+1<r) adj[i][j].push_back({seg,{i+1, j}});
            if(j+1<c) adj[i][j].push_back({seg,{i, j+1}});
            if(i-1 >= 0) adj[i][j].push_back({seg,{i-1, j}});
            if(j-1 >= 0) adj[i][j].push_back({seg,{i, j-1}});
        }
    }

    //printEdges(adj, vts);

    //fazer dfs para encontrar as sequencias snukes
    GraphUtils grafo(adj, vts, r, c);

    if(grafo.call()) cout << "Yes\n";
    else cout << "No\n";

    }

    return 0;
}