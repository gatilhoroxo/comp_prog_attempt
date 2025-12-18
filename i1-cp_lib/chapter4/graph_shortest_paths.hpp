#ifndef SHORTEST_PATHS_HPP
#define SHORTEST_PATHS_HPP

#include "cp_lib.hpp"

// ==================== Estruturas auxiliares ====================
struct Edge {
    int to, weight;
    Edge() : to(0), weight(0) {}
    Edge(int t, int w) : to(t), weight(w) {}
};

struct PriorityNode {
    int vertex, parent, dist;
    
    PriorityNode() : vertex(0), parent(0), dist(INF) {}
    PriorityNode(int v, int p, int d) : vertex(v), parent(p), dist(d) {}
    
    bool operator<(const PriorityNode& other) const {
        return dist > other.dist;  // Min heap
    }
};


// ==================== Shortest Paths ====================
// Uso: Dijkstra, Bellman-Ford, Floyd-Warshall
class ShortestPaths {
private:
    vector<vector<Edge>> adj;  // Lista de adjacência
    vvi matrix;                // Matriz de adjacência
    vi dist;                   // Distâncias
    vector<Edge> pred;         // Predecessores
    vector<bool> visited;
    priority_queue<PriorityNode> heap;
    int n;                     // Número de vértices

    void init_dijkstra() {
        for(int i = 0; i < n; i++) {
            dist[i] = INF;
            pred[i].to = -1;
            visited[i] = false;
        }
    }

    int get_weight(int u, int v) {
        for(auto& edge : adj[u]) {
            if(edge.to == v) return edge.weight;
        }
        return 0;
    }

public:
    ShortestPaths() {}
    
    ShortestPaths(int n_) : n(n_) {
        adj.resize(n);
        dist.resize(n);
        pred.resize(n);
        visited.resize(n);
    }

    // Adiciona aresta direcionada
    void add_edge(int u, int v, int w) {
        adj[u].push_back(Edge(v, w));
    }

    // ==================== Dijkstra (heap-based) ====================
    // Uso: SSSP em grafos com pesos não-negativos O((V+E) log V)
    void dijkstra_heap(int source) {
        init_dijkstra();
        heap.push(PriorityNode(source, source, 0));
        dist[source] = 0;
        
        for(int i = 0; i < n; i++) {
            PriorityNode current;
            do {
                if(!heap.empty()) {
                    current = heap.top();
                    heap.pop();
                }
                if(current.vertex == 0 && current.dist == INF && heap.empty()) 
                    return;
            } while(visited[current.vertex]);
            
            visited[current.vertex] = true;
            pred[current.vertex].to = current.parent;
            
            for(auto& edge : adj[current.vertex]) {
                int v = edge.to;
                int w = edge.weight;
                if(!visited[v] && dist[v] > dist[current.vertex] + w) {
                    dist[v] = dist[current.vertex] + w;
                    heap.push(PriorityNode(v, current.vertex, dist[v]));
                }
            }
        }
    }

    // ==================== Dijkstra com lazy deletion ====================
    // Versão mais simples e eficiente do Dijkstra
    void dijkstra_lazy(int source) {
        dist.assign(n, INF);
        dist[source] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push({0, source});
        
        while(!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int d = front.first;
            int u = front.second;
            
            if(d > dist[u]) continue;  // Lazy deletion
            
            for(auto& edge : adj[u]) {
                if(dist[u] + edge.weight < dist[edge.to]) {
                    dist[edge.to] = dist[u] + edge.weight;
                    pq.push({dist[edge.to], edge.to});
                }
            }
        }
    }

    // ==================== Bellman-Ford ====================
    // Uso: SSSP com pesos negativos O(VE)
    void bellman_ford(int source) {
        dist.assign(n, INF);
        dist[source] = 0;
        
        // Relaxa todas as arestas V-1 vezes
        for(int i = 0; i < n - 1; i++) {
            for(int u = 0; u < n; u++) {
                if(dist[u] == INF) continue;
                for(auto& edge : adj[u]) {
                    dist[edge.to] = min(dist[edge.to], dist[u] + edge.weight);
                }
            }
        }
    }

    // Detecta ciclo negativo
    bool has_negative_cycle(int source) {
        bellman_ford(source);
        
        // Tenta relaxar mais uma vez
        for(int u = 0; u < n; u++) {
            if(dist[u] == INF) continue;
            for(auto& edge : adj[u]) {
                if(dist[edge.to] > dist[u] + edge.weight) {
                    return true;  // Ciclo negativo detectado
                }
            }
        }
        return false;
    }

    // ==================== Floyd-Warshall ====================
    // Uso: APSP (All Pairs Shortest Path) O(V³)
    void init_floyd_warshall_matrix(vvi& D) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) D[i][j] = 0;
                else {
                    int w = get_weight(i, j);
                    D[i][j] = (w != 0) ? w : INF;
                }
            }
        }
    }

    void floyd_warshall(vvi& D) {
        init_floyd_warshall_matrix(D);
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(D[i][k] != INF && D[k][j] != INF) {
                        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                    }
                }
            }
        }
    }

    // ==================== Variações do Floyd-Warshall ====================
    
    // Transitive closure (Warshall)
    void warshall(vvi& reach) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    reach[i][j] |= (reach[i][k] & reach[k][j]);
                }
            }
        }
    }

    // Minimax path (minimizar o máximo)
    void minimax(vvi& D) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));
                }
            }
        }
    }

    // Maximin path (maximizar o mínimo)
    void maximin(vvi& D) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    D[i][j] = max(D[i][j], min(D[i][k], D[k][j]));
                }
            }
        }
    }

    // ==================== Path reconstruction ====================
    void print_path(int i, int j, vvi& parent) {
        if(i != j) print_path(i, parent[i][j], parent);
        cout << ' ' << j;
    }

    void reconstruct_all_paths() {
        vvi parent(n, vi(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                parent[i][j] = i;
            }
        }
        
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(matrix[i][k] + matrix[k][j] < matrix[i][j]) {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        
        // Exemplo: imprime caminho de 0 a 1
        // print_path(0, 1, parent);
    }

    // ==================== Getters ====================
    vi get_distances() { return dist; }
    int get_distance(int v) { return dist[v]; }
};

#endif // SHORTEST_PATHS_HPP
