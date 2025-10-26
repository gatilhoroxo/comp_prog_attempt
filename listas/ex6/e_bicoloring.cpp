//bicoloring
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

#define VISITED 1
#define UNVISITED 0

void bfs(vb& vt, vi& bic, vvi& link_vt, int start){
    queue<int> q;
    q.push(start);
    vt[start] = VISITED;
    bic[start] = 1;
    while(q.size() > 0){
        int v = q.front(); q.pop();
        int cor = (bic[v] == 1 ? 2: 1);
        //preVisit(v);
        for(auto&w:link_vt[v]){
            if(vt[w] == UNVISITED){
                vt[w] = VISITED;
                bic[w] = cor;
                q.push(w);
            }
        }
        //posVisit(v);
    }
}

int isBic(vvi& link_vt){
    vb vt(link_vt.size(), UNVISITED);
    vi bic(link_vt.size(), 0);
    for(int i=0; i<link_vt.size(); i++){
        if(vt[i] == UNVISITED){
            bfs(vt, bic, link_vt, i);
        }
    }
    for(int i=0; i<link_vt.size(); i++){
        int cor1 = bic[i];
        for(auto&j:link_vt[i]){
            if(bic[j] == cor1) return false;
        }
    }
    //for(auto&i:bic) cout << i << ' '; cout << '\n';
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int n; cin >> n;
        if(n == 0) break;
        int l; cin >> l;
        
        vvi vt(n);
        while(l--){
            int idx, jdx; 
            cin >> idx >> jdx;
            vt[idx].push_back(jdx);
            vt[jdx].push_back(idx);
        }
        if(isBic(vt)){
            cout << "BICOLORABLE.\n";
        } else {
            cout << "NOT BICOLORABLE.\n";
        }
    }
}