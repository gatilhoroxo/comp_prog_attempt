#include <bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

#define INFINY 15 << 27

#define VISITED 1
#define UNVISITED 0

#define BLANK 0
#define BLACK 2
#define RED 4

struct GraphUtils {
    vvii adjPairs; 
    vvi adjList;   
    int n = 0;

    GraphUtils() = default;
    GraphUtils(const vvii& ap): adjPairs(ap), n(ap.size()) {}
    GraphUtils(const vvi& al): adjList(al), n(al.size()) {}

    void dfs_pairs(vi& vt, int u){
        vt[u] = VISITED;
        for(int j=0; j<adjPairs[u].size(); j++){
            ii v = adjPairs[u][j];
            if(vt[v.first] == UNVISITED) dfs_pairs(vt, v.first);
        }
    }

    void dfs_list(vi& vt, int u){
        vt[u] = VISITED;
        for(auto j: adjList[u]){
            if(vt[j] == UNVISITED) dfs_list(vt, j);
        }
    }

    int connection_(){
        vi vt(n, UNVISITED);
        int cnx = 0;
        for(int i=0; i<n; i++){
            if(vt[i] == UNVISITED){
                dfs_list(vt, i);
                cnx++;
            }
        }
        return cnx;
    }

    int connected_components(){
        int numCC = 0;
        vi dfs_num(n, UNVISITED);
        for(int i=0; i<n; i++){
            if(dfs_num[i] == UNVISITED){
                cout << "CC " << ++numCC << ": ";
                dfs_list(dfs_num, i);
                cout << '\n';
            }
        }
        return numCC;
    }

    void bfs(vi& vt, int start){
        queue<int> q;
        q.push(start);
        vt[start] = VISITED;
        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto &w: adjList[v]){
                if(vt[w] == UNVISITED){
                    vt[w] = VISITED;
                    q.push(w);
                }
            }
        }
    }

    void topological(vi& dfs_num, vi& ts, int u){
        dfs_num[u] = VISITED;
        for(int j=0; j<adjPairs[u].size(); j++){
            ii v = adjPairs[u][j];
            if(dfs_num[v.first] == UNVISITED) topological(dfs_num, ts, v.first);
        }
        ts.push_back(u);
    }

    int conected_ts(){
        vi ts;
        vi dfs2_num(n, UNVISITED);
        for(int i=0; i<n; i++){
            if(dfs2_num[i] == UNVISITED) topological(dfs2_num, ts, i);
        }
        return 0;
    }

    int bicheck(){
        if(adjPairs.empty()) return 1;
        queue<int> q;
        q.push(0);
        vi color(n, BLANK);
        color[0] = BLACK;
        bool isBi = true;
        while(!q.empty() && isBi){
            int u = q.front(); q.pop();
            for(int j=0; j<adjPairs[u].size(); j++){
                ii v = adjPairs[u][j];
                if(color[v.first] == BLANK){
                    color[v.first] = (color[u] == BLACK ? RED : BLACK);
                    q.push(v.first);
                } else if(color[v.first] == color[u]){ isBi = false; break; }
            }
        }
        return isBi;
    }
};

//========================Flood Fill=============================

struct FloodFill {
    int R, C;
    vvi grid;
    vi dr, dc;

    FloodFill(int R_, int C_, const vvi& grid_)
        : R(R_), C(C_), grid(grid_) {
            dr.resize(8); dc.resize(8);
            dr = {1, 1, 0,-1,-1,-1, 0, 1};
            dc = {0, 1, 1, 1, 0,-1,-1,-1};
        }
    FloodFill(int R_, int C_, const vvi& grid_, const vi& dr_, const vi& dc_)
        : R(R_), C(C_), grid(grid_), dr(dr_), dc(dc_) {}

    int fill(int r, int c, char c1, char c2){
        if(r<0 || r>= R || c < 0 || c>= C) return 0;
        if(grid[r][c] != c1) return 0;
        int ans = 1;
        grid[r][c] = c2;
        for(int d=0; d<8; d++)
            ans += fill(r+dr[d], c+dc[d], c1, c2);
        return ans;
    }
};

// articulation point / bridge and Tarjan SCC algorithms
struct GraphAlgorithms {
    vvii adj;
    int dfsCounter = 0;
    int dfsRoot = 0;
    int rootChildren = 0;

    vi dfs_parent;
    vi dfs_low;
    vi dfs_num;
    vi articulation_vertex;
    vii bridge_vertex;

    // Tarjan-specific
    stack<int> S;
    vi visited;

    GraphAlgorithms() = default;
    GraphAlgorithms(const vvii& adj_): adj(adj_) {}

    void runArticulation(){
        int n = adj.size();
        dfs_parent.assign(n, 0);
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        articulation_vertex.assign(n, 0);
        bridge_vertex.clear();
        dfsCounter = 0;

        for(int i=0; i<n; i++){
            if(dfs_num[i] == UNVISITED){
                dfsRoot = i;
                rootChildren = 0;
                articulationRec(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
    }

    void articulationRec(int u){
        dfs_low[u] = dfs_num[u] = dfsCounter++;
        for(int j=0; j< adj[u].size(); j++){
            ii v = adj[u][j];
            if(dfs_num[v.first] == UNVISITED){
                dfs_parent[v.first] = u;
                if(u == dfsRoot) rootChildren++;

                articulationRec(v.first);

                if(dfs_low[v.first] >= dfs_num[u])
                    articulation_vertex[u] = true;
                if(dfs_low[v.first] > dfs_num[u])
                    bridge_vertex.push_back({u, v.first});
                dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
            } else if(v.first != dfs_parent[u])
                dfs_low[u] = min(dfs_low[u], dfs_num[v.first]);
        }
    }

    // Tarjan SCC
    void runTarjan(){
        int n = adj.size();
        dfs_low.assign(n, 0);
        dfs_num.assign(n, UNVISITED);
        visited.assign(n, false);
        while(!S.empty()) S.pop();
        dfsCounter = 0;

        for(int i=0; i<n; i++){
            if(dfs_num[i] == UNVISITED)
                tarjanRec(i);
        }
    }

    void tarjanRec(int u){
        dfs_low[u] = dfs_num[u] = dfsCounter++;
        S.push(u);
        visited[u] = true;
        for(int j=0; j< adj[u].size(); j++){
            ii v = adj[u][j];
            if(dfs_num[v.first] == UNVISITED)
                tarjanRec(v.first);
            if(visited[v.first])
                dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
        }

        if(dfs_low[u] == dfs_num[u]){
            while(true){
                int v = S.top(); S.pop();
                visited[v] = false;
                if(u == v) break;
            }
        }
    }
};

void call_artic(){
    int n=10;
    vvii adj(n, vii());
    GraphAlgorithms G(adj);
    G.runArticulation();
}

void call_tarjan(){
    int n=10;
    vvii adj(n, vii());
    GraphAlgorithms G(adj);
    G.runTarjan();
}

// ========================= mst ==========================


class UnionFind {
private: vi p, rank;
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i=0; i<N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

struct mst{
    vector<pair<int, ii>> edgelist;
    vvii adjl;
    int e, n;
    vi taken;
    priority_queue<ii> pq;
    mst(vector<pair<int, ii>> edgelist_, int n_) : edgelist(edgelist_), e(edgelist_.size()), n(n_) {
        taken.assign(n, UNVISITED);
    }

    bool cmp(pair<int, ii> a, pair<int, ii> b){
        return (a.first < b.first);
    }

    int kruskal(){
        int cost=0;
        UnionFind uf(n);
        for(int i=0; i<edgelist.size(); i++){
            pair<int, ii> front = edgelist[i];
            if(!uf.isSameSet(front.second.first, front.second.second)) {
                cost += front.first;
                uf.unionSet(front.second.first, front.second.second);
            }
        }
        return cost;
    }

    void prim(int vtx){
        taken[vtx] = 1; 
        for(int j=0; j< adjl[vtx].size(); j++){
            ii v = adjl[vtx][j];
            if(taken[v.first] == UNVISITED){
                pq.push(ii(-v.second, -v.first));
            }
        }
    }

    int callprim(){
        taken.assign(n, UNVISITED);
        prim(0);
        int cost = 0;
        while(!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int u = -front.second, w = -front.first;
            if(!taken[u]){
                cost += w; 
                prim(u);
            }
        }
        return cost;
    }
    
    void call_mst_k(){
        sort(edgelist.begin(), edgelist.end(), cmp);
        int cost = kruskal();
    }
};

// ==================== menor caminho ====================
struct priority{
    int v, w, peso;

    priority(){ v=0; w=0; peso=INFINY; }
    priority(int v1, int w1, int p){ v=v1; w=w1; peso=p; }

    // TO-DO: ver como se comporta
    bool operator<(const priority& other) const {
        return peso > other.peso;
    }
};


struct node {
    int id;
    int wt;
    node(){
        id=0;
        wt=0;
    }
    node(int c, int w){
        id = c;
        wt = w;
    }
};

class smallpath{
private:
    vector<vector<node>> lista;
    vvi matrix; //nao eh inicializado
    vi distancias;
    vector<node> predecessores;
    vector<bool> mark;
    priority_queue<priority> heap;
    int n;

    void predijkstra(){
        for(int i=0; i<n; i++){
            distancias[i] = INFINY;
            predecessores[i].id = -1;
            setMark(i, UNVISITED);
        }
    }
    void setMark(int v, bool val) {
        mark[v] = val;
    }
    bool getMark(int v) {
        return mark[v];
    }
    int weight(int v, int w){
        for(auto it: lista[v])
            if(it.id == w) return it.wt;
        return 0;
    }

public:
    //TO-DO rever implementação de dijkstra 
    smallpath(){

    }

    void dijkstra(int s){
        predijkstra();
        heap.push(priority(s,s,0));
        distancias[s] = 0;
        for(int i=0; i<n; i++){
            priority temp;
            do{
                //pode dar problema ??
                if(!heap.empty()) {
                    temp = heap.top();
                    heap.pop();
                }
                if(temp.v == 0 && temp.w == 0 && temp.peso == INFINY && heap.empty()) return;
            } while(getMark(temp.v) != UNVISITED);
            setMark(temp.v, VISITED); predecessores[temp.v].id = temp.w;
            for(auto it: lista[temp.v]){
                int w = it.id;
                if(getMark(w) != VISITED && distancias[w] > distancias[temp.v] + weight(temp.v,w)) {
                    distancias[w] = distancias[temp.v] + weight(temp.v, w);
                    heap.push(priority(temp.v, w, distancias[w]));
                }
            }
        }
    }


    // sssp on weighted graph
    void lazy_deletion(int s){
        distancias.assign(n, INTMAX_MAX);
        distancias[s] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq; 
        pq.push({0, s});
        while(!pq.empty()){
            ii front = pq.top(); 
            pq.pop();
            int d = front.first;
            int u = front.second;
            if(d > distancias[u]) continue;
            for(auto&v:lista[u]){
                if(distancias[u] + v.wt < distancias[v.id]){
                    distancias[v.id] = distancias[u] + v.wt;
                    pq.push({distancias[v.id], v.id});
                }
            }
        }
    }

    //bellman ford
    void bell(int s){
        distancias.assign(n, INTMAX_MIN);
        for(int i=0; i<n-1; i++){
            for(int u=0; u < n; u++){
                for(auto&v: lista[u]){
                    distancias[v.id] = min(distancias[v.id], distancias[u] + v.wt);
                }
            }
        }
    }

    //negative cycle
    bool bellnegative(int s){
        bell(s);
        bool hasNegCycle = false;
        for(int u=0; u<n; u++){
            for(auto&v:lista[u]){
                if(distancias[v.id] > distancias[u] + v.wt)
                    hasNegCycle = true;
            }
        }
        return hasNegCycle;
    }

    //apsp
    void floyd_setMatrix(vvi& D){
        for(int i=0; i< n; i++)
            for(int j=0; j<n; j++){
                if(i=j) D[i][j] = 0;
                else if(weight(i, j) != 0) D[i][j] = weight(i, j);
                else D[i][j] = INFINY;
            }
    }

    void Floyd_Warshall(vvi& D){
        floyd_setMatrix(D);
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                    if(D[i][k] != INFINY && D[k][j] != INFINY)
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    }

    //printando menor caminho

    void printPath(int i, int j, vvi&p){
        if(i!=j) printPath(i, p[i][j], p);
        cout << ' ' << j;
    }

    void print_path_main(){
        vvi p(n,vi(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                p[i][j] = i;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
            }

        //exemplo de print
        printPath(0, 1, p);
    }

    //transitive closure (warshall)
    void warshall(){
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] |= (matrix[i][k] & matrix[k][j]);
                }
            }
        }
    }

    void minmax(){
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = min(matrix[i][j], max(matrix[i][k], matrix[k][j]));
                }
            }
        }
    }

    void maxmin(){
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    matrix[i][j] = max(matrix[i][j], min(matrix[i][k], matrix[k][j]));
                }
            }
        }
    }

    //chapter 4.6 to 4.7
    void ford_fulkerson(){

    }

    void edmonds_karp(){

    }

    void fishmonger(){

    }

    void minimum_vertex_cover(){

    }

    void tree_tranversal(){

    }

    void euler_path(){

    }

    void augmenting_path_for_bi_graph(){
        
    }

};

// ==================== special graphs ====================

