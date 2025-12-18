//beverages
//finalmente foi
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using pqg = priority_queue<int, vector<int>, greater<int>>;

#define VISITED 1
#define UNVISITED 0


struct GraphUtils {
    vvi adj;   
    int n = 0;

    //GraphUtils() = default;
    GraphUtils(vvi& vt): adj(vt), n(vt.size()) {}

    void topological(vi& dfs_num, vi& ts, int u){
        dfs_num[u] = VISITED;
        for(int j=0; j<adj[u].size(); j++){
            int v = adj[u][j];
            if(dfs_num[v] == UNVISITED) topological(dfs_num, ts, v);
        }
        ts.push_back(u);
    }

    vi kahn_toposort(){
        vi indeg(n, 0);
        for(int u=0; u<n; ++u)
            for(auto v: adj[u]) indeg[v]++;
        pqg pq;
        for(int i=0; i<n; ++i) if(indeg[i] == 0) pq.push(i);
        
        vi res;
        while(!pq.empty()){
            int u = pq.top(); pq.pop();
            res.push_back(u);
            for(auto v: adj[u]){
                if(--indeg[v] == 0) pq.push(v);
            }
        }
        return res;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, t=0;
    while(cin >> n)
    {
        t++;
        map<string, int> msi;
        map<int,string> mis;
        for(int i=0; i<n; i++) {
            string temp; cin >> temp;
            msi[temp] = i;
            mis[i] = temp;
        } 

        int m; cin >> m;
        vvi vt(n);
        for(int i=0; i<m; i++){
            string temp1, temp2; 
            cin >> temp1 >> temp2; 
            // b1 < b2  => edge from b1 to b2
            vt[msi[temp1]].push_back(msi[temp2]);
        }


        cout << "Case #" << t << ": Dilbert should drink beverages in this order:";
        GraphUtils graph(vt);
        vi ts = graph.kahn_toposort();
        for(auto &i: ts) cout << ' ' << mis[i];
        cout << ".\n\n";
        /*
        for(int i=0; i<vt.size(); i++){
            cout << mis[i] << ": { ";
            for(auto&j:vt[i]){
                cout << mis[j] << ' ';
            }
            cout << "}\n";
        }
        cout << '\n';
        //*/

    }
    return 0;
}

