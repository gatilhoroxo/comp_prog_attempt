//Dominator
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vbb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;

#define VISITED 1
#define UNVISITED 0

void dfs(vb& vt, vvi& adj, int u){
    vt[u] = VISITED;
    for(int j=0; j<adj[u].size(); j++){
        if(adj[u][j] && vt[j] == UNVISITED ) { 
            dfs(vt, adj, j); }
    }
}

void dom(vvi& vt, vbb& ans){
    vb orig(vt.size(), UNVISITED);
    dfs(orig, vt, 0);

    for(int i=0; i<vt.size(); i++){
        vb reach(vt.size(), UNVISITED);

        reach[i] = VISITED;
        if(i != 0) dfs(reach, vt, 0);

        for(int j=0; j<vt.size(); j++){
            if(!orig[j]) ans[i][j] = false;  
            else if(i == j) ans[i][j] = true; 
            else ans[i][j] = (!reach[j]);  
        }
    }
}

void line(int n){
    cout << "+";
    for(int i=0; i<(2*n-1); i++){ cout << '-';}
    cout << "+\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >>tc;
    for(int t=0;t<tc;t++){
        int n; cin >> n;
        vvi vt(n, vi(n));
        for(auto&i:vt){ 
            for(auto&j:i){ 
                cin >> j;
            }
        }

        //process
        vbb ans(n, vb(n,UNVISITED));
        dom(vt, ans);
        
        //saida
        cout << "Case " << t +1 << ":\n"; 
        for(int i=0; i<n; i++){ 
            line(n); 
            for(int j=0; j<n; j++){ 
                cout << "|" << (ans[i][j] ? "Y" : "N");
            } 
            cout << "|\n";
        } 
        line(n);

    }

    return 0;
}