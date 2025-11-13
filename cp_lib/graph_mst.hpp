#ifndef MST_HPP
#define MST_HPP

#include "cp_lib.hpp"
#include "data_structures.hpp"

// ==================== Minimum Spanning Tree ====================
// Uso: Kruskal e Prim para encontrar MST

class MST {
private:
    vector<pair<int, ii>> edgelist;  // {peso, {u, v}}
    vvii adj;                         // Lista de adjacência {vizinho, peso}
    int num_edges, num_vertices;
    vi taken;                         // Marca vértices já incluídos (Prim)
    priority_queue<ii> pq;            // {-peso, -vértice} para min heap

    // Comparador para ordenar arestas por peso
    static bool compare_edges(pair<int, ii> a, pair<int, ii> b) {
        return a.first < b.first;
    }

public:
    MST(vector<pair<int, ii>> edges, int n) 
        : edgelist(edges), num_edges(edges.size()), num_vertices(n) {
        taken.assign(n, UNVISITED);
    }

    MST(vvii adjacency_list, int n)
        : adj(adjacency_list), num_vertices(n) {
        taken.assign(n, UNVISITED);
    }

    // ==================== Algoritmo de Kruskal ====================
    // Uso: MST usando ordenação de arestas + Union-Find O(E log E)
    int kruskal() {
        int mst_cost = 0;
        UnionFind uf(num_vertices);
        
        // Ordena arestas por peso
        sort(edgelist.begin(), edgelist.end(), compare_edges);
        
        for(int i = 0; i < edgelist.size(); i++) {
            pair<int, ii> edge = edgelist[i];
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            // Se u e v não estão conectados, adiciona aresta à MST
            if(!uf.isSameSet(u, v)) {
                mst_cost += weight;
                uf.unionSet(u, v);
            }
        }
        return mst_cost;
    }

    // ==================== Algoritmo de Prim ====================
    // Uso: MST crescendo a árvore vértice a vértice O(E log V)
    
    // Adiciona vértice à MST e suas arestas à fila de prioridade
    void process_vertex(int vtx) {
        taken[vtx] = VISITED;
        for(int j = 0; j < adj[vtx].size(); j++) {
            ii neighbor = adj[vtx][j];
            int v = neighbor.first;
            int weight = neighbor.second;
            
            if(taken[v] == UNVISITED) {
                // Usa negativos para simular min heap
                pq.push(ii(-weight, -v));
            }
        }
    }

    int prim(int start = 0) {
        taken.assign(num_vertices, UNVISITED);
        process_vertex(start);
        int mst_cost = 0;
        
        while(!pq.empty()) {
            ii front = pq.top(); pq.pop();
            int weight = -front.first;
            int u = -front.second;
            
            if(taken[u] == UNVISITED) {
                mst_cost += weight;
                process_vertex(u);
            }
        }
        return mst_cost;
    }

    // ==================== Kruskal com retorno de arestas ====================
    // Retorna as arestas que fazem parte da MST
    pair<int, vector<pair<int, ii>>> kruskal_with_edges() {
        int mst_cost = 0;
        vector<pair<int, ii>> mst_edges;
        UnionFind uf(num_vertices);
        
        sort(edgelist.begin(), edgelist.end(), compare_edges);
        
        for(auto& edge : edgelist) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if(!uf.isSameSet(u, v)) {
                mst_cost += weight;
                mst_edges.push_back(edge);
                uf.unionSet(u, v);
            }
        }
        return {mst_cost, mst_edges};
    }

    // ==================== Second Best MST ====================
    // Encontra a segunda melhor MST (útil em alguns problemas)
    int second_best_mst() {
        // Primeiro encontra a MST
        int mst_cost = 0;
        vector<pair<int, ii>> mst_edges;
        UnionFind uf(num_vertices);
        
        sort(edgelist.begin(), edgelist.end(), compare_edges);
        
        for(auto& edge : edgelist) {
            int weight = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            
            if(!uf.isSameSet(u, v)) {
                mst_cost += weight;
                mst_edges.push_back(edge);
                uf.unionSet(u, v);
            }
        }
        
        // Tenta remover cada aresta da MST e adicionar outra
        int second_best = INF;
        for(auto& excluded : mst_edges) {
            UnionFind uf2(num_vertices);
            int cost = 0;
            int edges_added = 0;
            
            for(auto& edge : edgelist) {
                if(edge == excluded) continue;
                
                int u = edge.second.first;
                int v = edge.second.second;
                
                if(!uf2.isSameSet(u, v)) {
                    cost += edge.first;
                    uf2.unionSet(u, v);
                    edges_added++;
                }
            }
            
            // Verifica se forma uma árvore geradora
            if(edges_added == num_vertices - 1) {
                second_best = min(second_best, cost);
            }
        }
        
        return second_best;
    }
};

#endif // MST_HPP
