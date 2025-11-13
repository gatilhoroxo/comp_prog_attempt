#ifndef GRAPH_ADVANCED_HPP
#define GRAPH_ADVANCED_HPP

#include "cp_lib.hpp"

// ==================== Articulation Points and Bridges ====================
// Uso: encontrar pontos e arestas críticas em grafos não-direcionados
class ArticulationPointsBridges {
public:
    vvi adj;
    int n, timer;
    vi disc, low, parent;
    vector<bool> visited, is_articulation;
    vii bridges;

    ArticulationPointsBridges(const vvi& graph) : adj(graph), n(graph.size()) {}

    void find_articulation_points_and_bridges() {
        timer = 0;
        disc.assign(n, -1);
        low.assign(n, -1);
        parent.assign(n, -1);
        visited.assign(n, false);
        is_articulation.assign(n, false);
        bridges.clear();

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bridge_dfs(i);
            }
        }
    }

    void bridge_dfs(int u) {
        visited[u] = true;
        disc[u] = low[u] = ++timer;
        int children = 0;

        for(int v : adj[u]) {
            if(!visited[v]) {
                children++;
                parent[v] = u;
                bridge_dfs(v);

                low[u] = min(low[u], low[v]);

                // Articulation point conditions
                if(parent[u] == -1 && children > 1) {
                    is_articulation[u] = true;
                }
                if(parent[u] != -1 && low[v] >= disc[u]) {
                    is_articulation[u] = true;
                }

                // Bridge condition
                if(low[v] > disc[u]) {
                    bridges.pb({u, v});
                }
            } else if(v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
    }

    vi get_articulation_points() {
        vi result;
        for(int i = 0; i < n; i++) {
            if(is_articulation[i]) {
                result.pb(i);
            }
        }
        return result;
    }

    vii get_bridges() {
        return bridges;
    }
};

// ==================== Strongly Connected Components (Tarjan) ====================
// Uso: encontrar SCCs em grafos direcionados
class StronglyConnectedComponents {
public:
    vvi adj;
    int n, timer, scc_count;
    vi disc, low, scc_id;
    vector<bool> in_stack;
    stack<int> st;

    StronglyConnectedComponents(const vvi& graph) : adj(graph), n(graph.size()) {}

    void find_sccs() {
        timer = scc_count = 0;
        disc.assign(n, -1);
        low.assign(n, -1);
        scc_id.assign(n, -1);
        in_stack.assign(n, false);
        
        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            if(disc[i] == -1) {
                tarjan_scc_dfs(i);
            }
        }
    }

    void tarjan_scc_dfs(int u) {
        disc[u] = low[u] = ++timer;
        st.push(u);
        in_stack[u] = true;

        for(int v : adj[u]) {
            if(disc[v] == -1) {
                tarjan_scc_dfs(v);
                low[u] = min(low[u], low[v]);
            } else if(in_stack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if(low[u] == disc[u]) {
            vi current_scc;
            while(true) {
                int v = st.top(); st.pop();
                in_stack[v] = false;
                scc_id[v] = scc_count;
                current_scc.pb(v);
                if(v == u) break;
            }
            scc_count++;
        }
    }

    int get_scc_count() {
        return scc_count;
    }

    vi get_scc_ids() {
        return scc_id;
    }

    // Constrói grafo condensado (DAG dos SCCs)
    vvi build_condensed_graph() {
        vvi condensed(scc_count);
        set<ii> edges;

        for(int u = 0; u < n; u++) {
            for(int v : adj[u]) {
                int scc_u = scc_id[u];
                int scc_v = scc_id[v];
                if(scc_u != scc_v && edges.find({scc_u, scc_v}) == edges.end()) {
                    condensed[scc_u].pb(scc_v);
                    edges.insert({scc_u, scc_v});
                }
            }
        }
        return condensed;
    }
};

// ==================== Tree Algorithms ====================
// Uso: algoritmos específicos para árvores
class TreeAlgorithms {
public:
    vvi adj;
    int n;
    vi parent, depth;

    TreeAlgorithms(const vvi& tree) : adj(tree), n(tree.size()) {
        parent.resize(n);
        depth.resize(n);
    }

    // Root the tree and compute parent/depth
    void root_tree(int root) {
        fill(parent.begin(), parent.end(), -1);
        fill(depth.begin(), depth.end(), 0);
        dfs_root(root, -1, 0);
    }

    void dfs_root(int u, int p, int d) {
        parent[u] = p;
        depth[u] = d;
        for(int v : adj[u]) {
            if(v != p) {
                dfs_root(v, u, d + 1);
            }
        }
    }

    // Find LCA using binary lifting
    vvi up;
    int LOG;

    void preprocess_lca(int root) {
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vi(LOG, -1));
        
        root_tree(root);
        
        for(int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }
        
        for(int j = 1; j < LOG; j++) {
            for(int i = 0; i < n; i++) {
                if(up[i][j-1] != -1) {
                    up[i][j] = up[up[i][j-1]][j-1];
                }
            }
        }
    }

    int lca(int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        
        int diff = depth[u] - depth[v];
        for(int i = 0; i < LOG; i++) {
            if((diff >> i) & 1) {
                u = up[u][i];
            }
        }
        
        if(u == v) return u;
        
        for(int i = LOG - 1; i >= 0; i--) {
            if(up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }

    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    // Tree diameter
    pair<int, ii> find_diameter() {
        // First DFS to find farthest node from arbitrary node
        auto [dist1, farthest1] = bfs_farthest(0);
        
        // Second DFS from farthest node to find actual diameter
        auto [diameter, farthest2] = bfs_farthest(farthest1);
        
        return {diameter, {farthest1, farthest2}};
    }

    pair<int, int> bfs_farthest(int start) {
        vi dist(n, -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        
        int farthest = start;
        int max_dist = 0;
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            
            for(int v : adj[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    
                    if(dist[v] > max_dist) {
                        max_dist = dist[v];
                        farthest = v;
                    }
                }
            }
        }
        
        return {max_dist, farthest};
    }

    // Tree centroid decomposition
    vi subtree_size;
    vector<bool> is_removed;

    void calculate_size(int u, int p) {
        subtree_size[u] = 1;
        for(int v : adj[u]) {
            if(v != p && !is_removed[v]) {
                calculate_size(v, u);
                subtree_size[u] += subtree_size[v];
            }
        }
    }

    int find_centroid(int u, int p, int tree_size) {
        for(int v : adj[u]) {
            if(v != p && !is_removed[v] && subtree_size[v] > tree_size / 2) {
                return find_centroid(v, u, tree_size);
            }
        }
        return u;
    }

    void decompose(int u) {
        calculate_size(u, -1);
        int centroid = find_centroid(u, -1, subtree_size[u]);
        
        is_removed[centroid] = true;
        
        // Process centroid here
        // ...
        
        for(int v : adj[centroid]) {
            if(!is_removed[v]) {
                decompose(v);
            }
        }
    }

    void centroid_decomposition() {
        subtree_size.resize(n);
        is_removed.assign(n, false);
        decompose(0);
    }
};

// ==================== Heavy-Light Decomposition ====================
// Uso: queries eficientes em caminhos de árvore
class HeavyLightDecomposition {
public:
    vvi adj;
    int n, timer;
    vi parent, depth, heavy, head, pos;

    HeavyLightDecomposition(const vvi& tree) : adj(tree), n(tree.size()) {
        parent.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        timer = 0;
    }

    void dfs1(int u) {
        int size = 1;
        int max_child_size = 0;
        
        for(int v : adj[u]) {
            if(v != parent[u]) {
                parent[v] = u;
                depth[v] = depth[u] + 1;
                dfs1(v);
                
                int child_size = 1; // Calculate actual child size here
                size += child_size;
                
                if(child_size > max_child_size) {
                    max_child_size = child_size;
                    heavy[u] = v;
                }
            }
        }
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = timer++;
        
        if(heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        
        for(int v : adj[u]) {
            if(v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

    void build(int root = 0) {
        parent[root] = -1;
        depth[root] = 0;
        dfs1(root);
        dfs2(root, root);
    }

    int lca(int u, int v) {
        while(head[u] != head[v]) {
            if(depth[head[u]] > depth[head[v]]) {
                u = parent[head[u]];
            } else {
                v = parent[head[v]];
            }
        }
        return depth[u] < depth[v] ? u : v;
    }

    // Query path from u to v
    void query_path(int u, int v) {
        while(head[u] != head[v]) {
            if(depth[head[u]] > depth[head[v]]) {
                // Query segment [pos[head[u]], pos[u]]
                u = parent[head[u]];
            } else {
                // Query segment [pos[head[v]], pos[v]]
                v = parent[head[v]];
            }
        }
        
        // Query segment [min(pos[u], pos[v]), max(pos[u], pos[v])]
    }
};

#endif // GRAPH_ADVANCED_HPP