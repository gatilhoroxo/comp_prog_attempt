//building teams
//aceito
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
//grafo bipartido
//sao apenas dois times
//nao pode ter amigos no mesmo time

#define VISITED 1
#define UNVISITED 0

#define BLANK 0
#define BLACK 2
#define RED 4

struct GraphUtils {
    vvi adj; 
    int n = 0;
    vi color;

    GraphUtils() = default;
    GraphUtils(const vvi& ap): adj(ap), n(ap.size()) {}

    int bicheck(int start){
        if(adj.empty()) return 1;
        queue<int> q;
        q.push(start);
        color[start] = BLACK;
        bool isBi = true;
        while(!q.empty() && isBi){
            int u = q.front(); q.pop();
            for(auto&v:adj[u]){
                if(color[v] == BLANK){
                    color[v] = (color[u] == BLACK ? RED : BLACK);
                    q.push(v);
                } else if(color[v] == color[u]){ 
                    isBi = false; 
                    break; 
                }
            }
        }

        return isBi;
    }

    bool call(){
        color.assign(n, BLANK);
        bool check = true;
        for(int i=0; i<n; i++){
            if(color[i] == BLANK) 
                check = bicheck(i);
        }
        return check;
    }

    void printCores(){
        for(auto&i:color){
            if(i == BLACK) cout << 1 << ' ';
            else cout << 2 << ' ';
        }
        cout << '\n';
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >>t; while(t--)
    {
        
    int n, m; 
    cin >> n >> m;
    vvi vt(n); 
    for(int i=0; i<m; i++) {
        int f,s;
        cin >> f >> s;
        vt[f-1].push_back(s-1);
        vt[s-1].push_back(f-1);
    }

    GraphUtils grafo(vt);

    if(grafo.call()) {
        grafo.printCores();
    } else cout << "IMPOSSIBLE\n";

    }

    return 0;
}
