//graph connectivity
//resolvi
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;

#define VISITED 1
#define UNVISITED 0

void dfs(vb& vt, vvi& link_vt, int u){
    vt[u] = VISITED;
    for(auto j:link_vt[u]){
        if(vt[j] == UNVISITED) { 
            dfs(vt, link_vt, j); }
    }
}

int conection(vvi& link_vt){
    vb vt(link_vt.size(), UNVISITED);
    int cnx = 0;
    for(int i=0; i<link_vt.size(); i++){
        if(vt[i] == UNVISITED){
            dfs(vt, link_vt, i);
            cnx++;
        }
    }
    return cnx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        char ch; cin >> ch;
        cin.ignore();
        int n = abs('A' - ch) +1;
        vvi vt(n);

        string s;
        while(getline(cin,s) && !s.empty()){
            int idx = abs('A' - s[0]);
            int jdx = abs('A' - s[1]);
            //cout << n << ' ' << idx << ' ' << jdx << ' ' << 'o' << endl;
            vt[idx].push_back(jdx);
            vt[jdx].push_back(idx);
        }
        cout << conection(vt) << '\n';
        if(t) cout << '\n';
    }

    return 0;
}