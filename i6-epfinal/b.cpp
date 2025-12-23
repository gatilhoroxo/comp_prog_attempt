//dijkstra
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using vi = vector<ll>; using vvi = vector<vi>;
using vii = vector<ii>; using vvii = vector<vii>;
const ll INF = 1e18;

struct par{
    int i;
    int j;
    ll w;
    par(){
        i=j=w=0; 
    }
    par(int a, int b, ll c){
        i = a;
        j = b;
        w = c;
    }
    par(ii p){
        i = p.first;
        j = p.first;
        w = p.second;
    }
    bool operator<(const par& other) const {
        return w > other.w;  // Min heap
    }
};

class grafo {
private:
    vvii adj;
    vvi list;
    ll n;
    vi dist;
    vector<bool> visited;
    priority_queue<par,vector<par>> heap;

    void init_dijkstra() {
        for(ll i = 0; i < n; i++) {
            dist[i] = INF;
            visited[i] = false;
        }
    }

    void setMark(int v, bool val) {
        visited[v] = val;
    }
    bool getMark(int v) {
        return visited[v];
    }

public:
    vi getDist(){
        return dist;
    }

    grafo(vvii& g) : adj(g), n(g.size()) {
        dist.resize(n, INF);
        visited.resize(n,false);
    }

    void dijkstra() {
        init_dijkstra();
        heap.push(par(0, 0, 0));
        dist[0] = 0;

        while(!heap.empty()){
            par front = heap.top(); 
            heap.pop();
            ll d = front.w; 
            ll u = front.j; 
            if(d > dist[u]) continue;
            for(auto&v:adj[u]){
                if(dist[u] != INF){
                    if(dist[u] + v.second < dist[v.first]){
                        dist[v.first] = dist[u] + v.second;
                        heap.push(par(u,v.first,dist[v.first]));
                    }
                } 
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    int n, m; 
    cin >> n >> m;
    int a,b,c;
    vector<vector<ii>> vt(n);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        vt[a-1].push_back({b-1,c});
    }

    grafo path(vt);
    path.dijkstra();
    vi dist = path.getDist();

    for(auto&i:dist){
        cout << i << ' ';
    } cout << '\n';

    }

    return 0;
}
