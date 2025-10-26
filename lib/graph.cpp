#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
using vvii = vector<vii>;

#define VISITED 1
#define UNVISITED -1
//dfs simples
void dfs(vi& vt, vvii& adj_vt, int u){
    vt[u] = VISITED;
    for(int j=0; j<adj_vt[u].size(); j++){
        ii v = adj_vt[u][j];
        if(vt[v.first] == UNVISITED) { dfs(vt, adj_vt, v.first); }

    }
}
// TO DO: fazer uma função que percorre todos os nós

