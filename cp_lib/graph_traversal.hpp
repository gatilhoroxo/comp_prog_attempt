#ifndef GRAPH_TRAVERSAL_HPP
#define GRAPH_TRAVERSAL_HPP

#include "cp_lib.hpp"

// ==================== Graph Traversal ====================
// Uso: DFS, BFS básicos e suas variações
class GraphTraversal {
public:
    vvi adj;
    int n;

    GraphTraversal(const vvi& graph) : adj(graph), n(graph.size()) {}
    GraphTraversal(int vertices) : n(vertices) { adj.resize(n); }

    void add_edge(int u, int v) {
        adj[u].pb(v);
    }

    void add_undirected_edge(int u, int v) {
        adj[u].pb(v);
        adj[v].pb(u);
    }

    // DFS recursivo básico
    void dfs(int u, vi& visited, vi& path) {
        visited[u] = VISITED;
        path.pb(u);
        for(int v : adj[u]) {
            if(visited[v] == UNVISITED) {
                dfs(v, visited, path);
            }
        }
    }

    // DFS iterativo
    vi dfs_iterative(int start) {
        vi visited(n, UNVISITED);
        vi path;
        stack<int> st;
        
        st.push(start);
        while(!st.empty()) {
            int u = st.top(); st.pop();
            if(visited[u] == UNVISITED) {
                visited[u] = VISITED;
                path.pb(u);
                for(int i = adj[u].size() - 1; i >= 0; i--) {
                    if(visited[adj[u][i]] == UNVISITED) {
                        st.push(adj[u][i]);
                    }
                }
            }
        }
        return path;
    }

    // BFS com distâncias
    pair<vi, vi> bfs_with_distances(int start) {
        vi visited(n, UNVISITED);
        vi distance(n, -1);
        queue<int> q;
        
        q.push(start);
        visited[start] = VISITED;
        distance[start] = 0;
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int v : adj[u]) {
                if(visited[v] == UNVISITED) {
                    visited[v] = VISITED;
                    distance[v] = distance[u] + 1;
                    q.push(v);
                }
            }
        }
        return {visited, distance};
    }

    // Encontra todos os caminhos simples entre dois vértices
    void find_all_paths(int start, int end, vi& path, vvi& all_paths, vi& visited) {
        path.pb(start);
        visited[start] = VISITED;
        
        if(start == end) {
            all_paths.pb(path);
        } else {
            for(int v : adj[start]) {
                if(visited[v] == UNVISITED) {
                    find_all_paths(v, end, path, all_paths, visited);
                }
            }
        }
        
        path.pop_back();
        visited[start] = UNVISITED;
    }
};

// ==================== Connected Components ====================
// Uso: componentes conexos e análise de conectividade
class ConnectedComponents {
public:
    vvi adj;
    int n;
    vi component;
    int num_components;

    ConnectedComponents(const vvi& graph) : adj(graph), n(graph.size()) {
        component.resize(n);
    }

    void dfs(int u, int comp_id) {
        component[u] = comp_id;
        for(int v : adj[u]) {
            if(component[v] == -1) {
                dfs(v, comp_id);
            }
        }
    }

    int find_components() {
        fill(component.begin(), component.end(), -1);
        num_components = 0;
        
        for(int i = 0; i < n; i++) {
            if(component[i] == -1) {
                dfs(i, num_components);
                num_components++;
            }
        }
        return num_components;
    }

    bool are_connected(int u, int v) {
        if(component.empty()) find_components();
        return component[u] == component[v];
    }

    vvi get_component_lists() {
        if(component.empty()) find_components();
        vvi components(num_components);
        for(int i = 0; i < n; i++) {
            components[component[i]].pb(i);
        }
        return components;
    }
};

// ==================== Topological Sort ====================
// Uso: ordenação topológica em DAGs
class TopologicalSort {
public:
    vvi adj;
    int n;

    TopologicalSort(const vvi& graph) : adj(graph), n(graph.size()) {}

    // Kahn's Algorithm (BFS-based)
    vi kahn_algorithm() {
        vi indegree(n, 0);
        for(int u = 0; u < n; u++) {
            for(int v : adj[u]) {
                indegree[v]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vi topo_order;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            topo_order.pb(u);
            
            for(int v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return (topo_order.size() == n) ? topo_order : vi(); // Empty if cycle
    }

    // DFS-based topological sort
    void dfs_topo(int u, vi& visited, vi& topo_order) {
        visited[u] = VISITED;
        for(int v : adj[u]) {
            if(visited[v] == UNVISITED) {
                dfs_topo(v, visited, topo_order);
            }
        }
        topo_order.pb(u);
    }

    vi dfs_topological_sort() {
        vi visited(n, UNVISITED);
        vi topo_order;
        
        for(int i = 0; i < n; i++) {
            if(visited[i] == UNVISITED) {
                dfs_topo(i, visited, topo_order);
            }
        }
        
        reverse(topo_order.begin(), topo_order.end());
        return topo_order;
    }

    // Detecta ciclo em DAG
    bool has_cycle() {
        vi topo = kahn_algorithm();
        return topo.size() != n;
    }
};

// ==================== Cycle Detection ====================
// Uso: detectar ciclos em grafos direcionados e não-direcionados
class CycleDetection {
public:
    vvi adj;
    int n;

    CycleDetection(const vvi& graph) : adj(graph), n(graph.size()) {}

    // Detecta ciclo em grafo não-direcionado
    bool has_cycle_undirected() {
        vi visited(n, UNVISITED);
        for(int i = 0; i < n; i++) {
            if(visited[i] == UNVISITED) {
                if(dfs_undirected(i, -1, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs_undirected(int u, int parent, vi& visited) {
        visited[u] = VISITED;
        for(int v : adj[u]) {
            if(v == parent) continue;
            if(visited[v] == VISITED || dfs_undirected(v, u, visited)) {
                return true;
            }
        }
        return false;
    }

    // Detecta ciclo em grafo direcionado
    bool has_cycle_directed() {
        vi color(n, 0); // 0: branco, 1: cinza, 2: preto
        for(int i = 0; i < n; i++) {
            if(color[i] == 0 && dfs_directed(i, color)) {
                return true;
            }
        }
        return false;
    }

    bool dfs_directed(int u, vi& color) {
        color[u] = 1; // cinza
        for(int v : adj[u]) {
            if(color[v] == 1 || (color[v] == 0 && dfs_directed(v, color))) {
                return true;
            }
        }
        color[u] = 2; // preto
        return false;
    }

    // Encontra um ciclo em grafo direcionado
    vi find_cycle_directed() {
        vi color(n, 0);
        vi parent(n, -1);
        vi cycle;
        
        function<bool(int)> dfs = [&](int u) -> bool {
            color[u] = 1;
            for(int v : adj[u]) {
                if(color[v] == 1) {
                    // Encontrou back edge, reconstruir ciclo
                    int cur = u;
                    cycle.pb(v);
                    while(cur != v) {
                        cycle.pb(cur);
                        cur = parent[cur];
                    }
                    reverse(cycle.begin(), cycle.end());
                    return true;
                } else if(color[v] == 0) {
                    parent[v] = u;
                    if(dfs(v)) return true;
                }
            }
            color[u] = 2;
            return false;
        };
        
        for(int i = 0; i < n; i++) {
            if(color[i] == 0 && dfs(i)) {
                return cycle;
            }
        }
        return {}; // Sem ciclo
    }
};

#endif // GRAPH_TRAVERSAL_HPP