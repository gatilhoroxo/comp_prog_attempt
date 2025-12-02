#ifndef GRAPH_SPECIAL_HPP
#define GRAPH_SPECIAL_HPP

#include "cp_lib.hpp"

// ==================== Bipartite Graph ====================
// Uso: verificação e coloração de grafos bipartidos
class BipartiteGraph {
public:
    vvi adj;
    int n;
    vi color;
    bool is_bipartite_flag;

    BipartiteGraph(const vvi& graph) : adj(graph), n(graph.size()) {
        color.resize(n);
    }

    bool check_bipartite() {
        fill(color.begin(), color.end(), -1);
        is_bipartite_flag = true;
        
        for(int i = 0; i < n && is_bipartite_flag; i++) {
            if(color[i] == -1) {
                bfs_color(i);
            }
        }
        return is_bipartite_flag;
    }

    void bfs_color(int start) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty() && is_bipartite_flag) {
            int u = q.front(); q.pop();
            
            for(int v : adj[u]) {
                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if(color[v] == color[u]) {
                    is_bipartite_flag = false;
                    return;
                }
            }
        }
    }

    pair<vi, vi> get_partition() {
        if(!check_bipartite()) return {{}, {}};
        
        vi set1, set2;
        for(int i = 0; i < n; i++) {
            if(color[i] == 0) set1.pb(i);
            else set2.pb(i);
        }
        return {set1, set2};
    }

    // Maximum Bipartite Matching (Kuhn's Algorithm)
    vi match;
    vi used;

    bool dfs_kuhn(int v, const vvi& graph) {
        if(used[v]) return false;
        used[v] = true;
        
        for(int to : graph[v]) {
            if(match[to] == -1 || dfs_kuhn(match[to], graph)) {
                match[to] = v;
                return true;
            }
        }
        return false;
    }

    int maximum_bipartite_matching(const vvi& left_to_right) {
        int left_size = left_to_right.size();
        int right_size = 0;
        for(const auto& edges : left_to_right) {
            for(int v : edges) {
                right_size = max(right_size, v + 1);
            }
        }
        
        match.assign(right_size, -1);
        used.resize(left_size);
        
        int result = 0;
        for(int v = 0; v < left_size; v++) {
            fill(used.begin(), used.end(), false);
            if(dfs_kuhn(v, left_to_right)) {
                result++;
            }
        }
        return result;
    }
};

// ==================== Flood Fill ====================
// Uso: preencher regiões conectadas em grid
class FloodFill {
public:
    int R, C;
    vvi grid;
    vi dr, dc;

    FloodFill(int R_, int C_) : R(R_), C(C_) {
        grid.resize(R, vi(C));
        // 8 direções padrão
        dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        dc = {-1, 0, 1, -1, 1, -1, 0, 1};
    }

    FloodFill(int R_, int C_, const vvi& grid_) : R(R_), C(C_), grid(grid_) {
        dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        dc = {-1, 0, 1, -1, 1, -1, 0, 1};
    }

    // 4-direções (apenas adjacentes ortogonais)
    void set_4_directions() {
        dr = {-1, 0, 1, 0};
        dc = {0, 1, 0, -1};
    }

    bool is_valid(int r, int c) {
        return r >= 0 && r < R && c >= 0 && c < C;
    }

    // Flood fill recursivo
    int flood_fill_recursive(int r, int c, int old_color, int new_color) {
        if(!is_valid(r, c) || grid[r][c] != old_color) return 0;
        
        int count = 1;
        grid[r][c] = new_color;
        
        for(int d = 0; d < dr.size(); d++) {
            count += flood_fill_recursive(r + dr[d], c + dc[d], old_color, new_color);
        }
        return count;
    }

    // Flood fill iterativo (evita stack overflow)
    int flood_fill_iterative(int start_r, int start_c, int old_color, int new_color) {
        if(!is_valid(start_r, start_c) || grid[start_r][start_c] != old_color) return 0;
        
        queue<ii> q;
        q.push({start_r, start_c});
        grid[start_r][start_c] = new_color;
        int count = 1;
        
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            
            for(int d = 0; d < dr.size(); d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if(is_valid(nr, nc) && grid[nr][nc] == old_color) {
                    grid[nr][nc] = new_color;
                    q.push({nr, nc});
                    count++;
                }
            }
        }
        return count;
    }

    // Encontra todas as componentes conectadas
    vii find_all_components(int target_color) {
        vvi visited(R, vi(C, false));
        vii components; // {tamanho, componente_id}
        int comp_id = 0;
        
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(!visited[i][j] && grid[i][j] == target_color) {
                    int size = bfs_component_size(i, j, target_color, visited);
                    components.pb({size, comp_id++});
                }
            }
        }
        return components;
    }

private:
    int bfs_component_size(int start_r, int start_c, int target_color, vvi& visited) {
        queue<ii> q;
        q.push({start_r, start_c});
        visited[start_r][start_c] = true;
        int size = 1;
        
        while(!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            
            for(int d = 0; d < dr.size(); d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                
                if(is_valid(nr, nc) && !visited[nr][nc] && grid[nr][nc] == target_color) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                    size++;
                }
            }
        }
        return size;
    }
};

// ==================== Graph Coloring ====================
// Uso: coloração de grafos
class GraphColoring {
public:
    vvi adj;
    int n;

    GraphColoring(const vvi& graph) : adj(graph), n(graph.size()) {}

    // Algoritmo guloso de coloração
    vi greedy_coloring() {
        vi color(n, -1);
        vector<bool> available(n, true);
        
        color[0] = 0; // Primeira cor para primeiro vértice
        
        for(int u = 1; u < n; u++) {
            // Marcar cores indisponíveis
            for(int v : adj[u]) {
                if(color[v] != -1) {
                    available[color[v]] = false;
                }
            }
            
            // Encontrar primeira cor disponível
            int c = 0;
            while(c < n && !available[c]) c++;
            color[u] = c;
            
            // Resetar disponibilidade
            fill(available.begin(), available.end(), true);
        }
        
        return color;
    }

    // Número cromático (aproximado com algoritmo guloso)
    int chromatic_number() {
        vi coloring = greedy_coloring();
        int max_color = 0;
        for(int c : coloring) {
            max_color = max(max_color, c);
        }
        return max_color + 1;
    }

    // Verifica se k-coloração é possível (backtracking)
    bool is_k_colorable(int k) {
        vi color(n, -1);
        return backtrack_coloring(0, k, color);
    }

private:
    bool backtrack_coloring(int u, int k, vi& color) {
        if(u == n) return true;
        
        for(int c = 0; c < k; c++) {
            bool safe = true;
            for(int v : adj[u]) {
                if(color[v] == c) {
                    safe = false;
                    break;
                }
            }
            
            if(safe) {
                color[u] = c;
                if(backtrack_coloring(u + 1, k, color)) {
                    return true;
                }
                color[u] = -1;
            }
        }
        return false;
    }
};

// ==================== Euler Path and Circuit ====================
// Uso: encontrar caminhos e circuitos eulerianos
class EulerianPath {
public:
    vvi adj;
    int n;

    EulerianPath(const vvi& graph) : adj(graph), n(graph.size()) {}

    // Verifica se tem caminho euleriano (grafo não-direcionado)
    bool has_eulerian_path_undirected() {
        if(!is_connected()) return false;
        
        int odd_degree = 0;
        for(int i = 0; i < n; i++) {
            if(adj[i].size() % 2 == 1) {
                odd_degree++;
            }
        }
        return odd_degree == 0 || odd_degree == 2;
    }

    // Verifica se tem circuito euleriano (grafo não-direcionado)
    bool has_eulerian_circuit_undirected() {
        if(!is_connected()) return false;
        
        for(int i = 0; i < n; i++) {
            if(adj[i].size() % 2 == 1) {
                return false;
            }
        }
        return true;
    }

    // Algoritmo de Hierholzer para encontrar circuito euleriano
    vi find_eulerian_circuit() {
        if(!has_eulerian_circuit_undirected()) return {};
        
        vvi temp_adj = adj;
        vi circuit;
        stack<int> curr_path;
        curr_path.push(0);
        
        while(!curr_path.empty()) {
            int u = curr_path.top();
            if(!temp_adj[u].empty()) {
                int v = temp_adj[u].back();
                temp_adj[u].pop_back();
                
                // Remove aresta u-v e v-u
                auto it = find(temp_adj[v].begin(), temp_adj[v].end(), u);
                if(it != temp_adj[v].end()) {
                    temp_adj[v].erase(it);
                }
                
                curr_path.push(v);
            } else {
                circuit.pb(u);
                curr_path.pop();
            }
        }
        
        reverse(circuit.begin(), circuit.end());
        return circuit;
    }

private:
    bool is_connected() {
        vi visited(n, false);
        int start = -1;
        
        // Encontra primeiro vértice com grau > 0
        for(int i = 0; i < n; i++) {
            if(!adj[i].empty()) {
                start = i;
                break;
            }
        }
        
        if(start == -1) return true; // Grafo sem arestas
        
        // DFS
        function<void(int)> dfs = [&](int u) {
            visited[u] = true;
            for(int v : adj[u]) {
                if(!visited[v]) {
                    dfs(v);
                }
            }
        };
        
        dfs(start);
        
        // Verifica se todos os vértices com grau > 0 foram visitados
        for(int i = 0; i < n; i++) {
            if(!adj[i].empty() && !visited[i]) {
                return false;
            }
        }
        return true;
    }
};

// ==================== Maximum Independent Set ====================
// Uso: encontrar conjunto independente máximo (NP-hard, algoritmo exponencial)
class MaximumIndependentSet {
public:
    vvi adj;
    int n;

    MaximumIndependentSet(const vvi& graph) : adj(graph), n(graph.size()) {}

    // Para grafos pequenos (n <= 20)
    vi find_maximum_independent_set() {
        vi best_set;
        int max_size = 0;
        
        // Enumerar todos os subconjuntos
        for(int mask = 0; mask < (1 << n); mask++) {
            vi current_set;
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) {
                    current_set.pb(i);
                }
            }
            
            if(is_independent_set(current_set) && current_set.size() > max_size) {
                max_size = current_set.size();
                best_set = current_set;
            }
        }
        
        return best_set;
    }

    // Algoritmo guloso (aproximação)
    vi greedy_independent_set() {
        vi degrees(n);
        for(int i = 0; i < n; i++) {
            degrees[i] = adj[i].size();
        }
        
        vi independent_set;
        vector<bool> used(n, false);
        
        while(true) {
            // Encontrar vértice de menor grau não usado
            int min_degree = n + 1;
            int chosen = -1;
            
            for(int i = 0; i < n; i++) {
                if(!used[i] && degrees[i] < min_degree) {
                    min_degree = degrees[i];
                    chosen = i;
                }
            }
            
            if(chosen == -1) break;
            
            // Adicionar ao conjunto independente
            independent_set.pb(chosen);
            used[chosen] = true;
            
            // Remover vizinhos
            for(int v : adj[chosen]) {
                if(!used[v]) {
                    used[v] = true;
                    // Atualizar graus dos vizinhos dos vizinhos
                    for(int u : adj[v]) {
                        if(!used[u]) {
                            degrees[u]--;
                        }
                    }
                }
            }
        }
        
        return independent_set;
    }

private:
    bool is_independent_set(const vi& vertices) {
        for(int i = 0; i < vertices.size(); i++) {
            for(int j = i + 1; j < vertices.size(); j++) {
                int u = vertices[i], v = vertices[j];
                if(find(adj[u].begin(), adj[u].end(), v) != adj[u].end()) {
                    return false;
                }
            }
        }
        return true;
    }
};

#endif // GRAPH_SPECIAL_HPP