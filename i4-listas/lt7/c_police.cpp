#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using vii = vector<pair<ll,ll>>;

struct Edge { 
    int to; 
    int rev; 
    int cap; 
};

struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vi level, it;
    Dinic(int n=0){
        N = n; G.assign(n,{}); 
        level.assign(n,0); 
        it.assign(n,0); 
    }
    void addEdgeDirected(int u,int v,int c){
        Edge a={v,(int)G[v].size(),c};
        Edge b={u,(int)G[u].size(),0};
        G[u].push_back(a);
        G[v].push_back(b);
    }
    bool bfs(int s,int t){
        fill(level.begin(), level.end(), -1);
        queue<int>q; q.push(s); level[s]=0;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(const Edge &e: G[u]){
                if(level[e.to] < 0 && e.cap>0){ level[e.to]=level[u]+1; q.push(e.to); }
            }
        }
        return level[t]>=0;
    }
    int dfs(int u,int t,int f){
        if(u==t) return f;
        for(ll &i=it[u]; i<(int)G[u].size(); i++){
            Edge &e = G[u][i];
            if(e.cap>0 && level[e.to]==level[u]+1){
                int got = dfs(e.to,t,min(f,e.cap));
                if(got>0){
                    e.cap -= got;
                    G[e.to][e.rev].cap += got;
                    return got;
                }
            }
        }
        return 0;
    }
    ll maxflow(int s,int t){
        ll flow=0;
        while(bfs(s,t)){
            fill(it.begin(), it.end(), 0);
            while(true){
                int f = dfs(s,t,INT_MAX);
                if(!f) break;
                flow += f;
            }
        }
        return flow;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {
    
    int n,m;
    cin>>n>>m;
    vii edges(m);
    Dinic D(n);
    for(auto &it: edges){  // CORREÇÃO: usar referência &
        cin>>it.first>>it.second;
        D.addEdgeDirected(it.first-1,it.second-1,1);
        D.addEdgeDirected(it.second-1,it.first-1,1);
    }

    ll flow = D.maxflow(0,n-1);

    vi vis(n,0);
    queue<int>q; 
    q.push(0); vis[0]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        for(const Edge &e: D.G[u]){
            if(e.cap>0 && !vis[e.to]){ 
                vis[e.to]=1; 
                q.push(e.to); 
            }
        }
    }

    vii cut;
    for(auto &ed: edges){
        int u = ed.first-1, v = ed.second-1;  // CORREÇÃO: converter para 0-indexed
        if(vis[u] && !vis[v])
            cut.push_back({ed.first, ed.second});
        else if(vis[v] && !vis[u]) 
            cut.push_back({ed.second, ed.first});
    }

    cout << cut.size() << '\n';
    for(auto &p: cut) 
        cout << p.first << ' ' << p.second << '\n';

    //cout << endl;
    }
    return 0;
}
