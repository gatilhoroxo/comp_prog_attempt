//building roads
//dfs
//grafo bidirecional
//arestas necessárias para ligar as cidades
//guardar a ponta (no) e o ultimo no do componente conexo
#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

#define VISITED 1
#define UNVISITED 0

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

    vi conected_comp(){
        vi vt(n, UNVISITED);
        vi cities;
        for(int i=0; i<n; i++){
            if(vt[i] == UNVISITED){
                dfs_list(vt, i);
                cities.push_back(i+1);
            }
        }

        return cities;
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

    int n,m; cin >> n >> m;
    // vector<int> vt(n);
    // for(int i=0; i<n; i++){
    //     vt[i] = i+1;
    // }
    vector<vector<int>> adj(n);
    for(int i=0; i<m; i++){
        int tmp1,tmp2; 
        cin >> tmp1 >>tmp2;
        adj[tmp1-1].push_back(tmp2-1);
        adj[tmp2-1].push_back(tmp1-1);
    }

    GraphUtils grafo(adj);

    vi cities = grafo.conected_comp();
    cout << cities.size()-1<< '\n';
    int c = cities[0];
    for(int i=1; i<cities.size(); i++){
        cout << c << ' ' << cities[i] << '\n';
    }

    }

    return 0;
}
