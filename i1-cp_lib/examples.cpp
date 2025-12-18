// ==================== EXEMPLO DE USO DA BIBLIOTECA ====================
// Este arquivo demonstra como usar cada módulo da biblioteca

#include "cp_lib.hpp"
#include "data_structures.hpp"
#include "graphs.hpp"
#include "dynamic_programming.hpp"

// ==================== Exemplo 1: Segment Tree ====================
void exemplo_segment_tree() {
    cout << "\n=== EXEMPLO: Segment Tree ===\n";
    vi arr = {3, 2, 4, 5, 1, 1, 5, 3};
    SegmentTree st(arr);
    
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";
    
    cout << "Mínimo [1, 5]: " << st.rmq(1, 5) << "\n";
    cout << "Mínimo [3, 7]: " << st.rmq(3, 7) << "\n";
    
    st.modify(5, 10);
    cout << "Após modificar posição 5 para 10\n";
    cout << "Mínimo [3, 7]: " << st.rmq(3, 7) << "\n";
}

// ==================== Exemplo 2: Fenwick Tree ====================
void exemplo_fenwick_tree() {
    cout << "\n=== EXEMPLO: Fenwick Tree ===\n";
    FenwickTree ft(10);
    
    // Adiciona valores
    for(int i = 1; i <= 10; i++) {
        ft.adjust(i, i);  // ft[i] = i
    }
    
    cout << "Soma [1, 5]: " << ft.rsq(1, 5) << "\n";  // 1+2+3+4+5 = 15
    cout << "Soma [3, 7]: " << ft.rsq(3, 7) << "\n";  // 3+4+5+6+7 = 25
    
    ft.adjust(5, 10);  // Adiciona 10 ao índice 5
    cout << "Após adicionar 10 ao índice 5\n";
    cout << "Soma [3, 7]: " << ft.rsq(3, 7) << "\n";  // 35
}

// ==================== Exemplo 3: Union-Find ====================
void exemplo_union_find() {
    cout << "\n=== EXEMPLO: Union-Find ===\n";
    UnionFind uf(10);
    
    uf.unionSet(1, 2);
    uf.unionSet(2, 3);
    uf.unionSet(4, 5);
    
    cout << "1 e 3 no mesmo conjunto? " << (uf.isSameSet(1, 3) ? "Sim" : "Não") << "\n";
    cout << "1 e 4 no mesmo conjunto? " << (uf.isSameSet(1, 4) ? "Sim" : "Não") << "\n";
    
    uf.unionSet(3, 4);
    cout << "Após unir 3 e 4:\n";
    cout << "1 e 5 no mesmo conjunto? " << (uf.isSameSet(1, 5) ? "Sim" : "Não") << "\n";
}

// ==================== Exemplo 4: Graph Traversal e Componentes ====================
void exemplo_graph_traversal() {
    cout << "\n=== EXEMPLO: Graph Traversal ===\n";
    int n = 7;
    GraphTraversal gt(n);
    
    // Grafo: 0-1-2, 3-4, 5-6
    gt.add_undirected_edge(0, 1);
    gt.add_undirected_edge(1, 2);
    gt.add_undirected_edge(3, 4);
    gt.add_undirected_edge(5, 6);
    
    // DFS iterativo
    vi path = gt.dfs_iterative(0);
    cout << "DFS iterativo a partir de 0: ";
    for(int v : path) cout << v << " ";
    cout << "\n";
    
    // BFS com distâncias
    auto [visited, distances] = gt.bfs_with_distances(0);
    cout << "Distâncias BFS a partir de 0: ";
    for(int i = 0; i < n; i++) {
        cout << "(" << i << ":" << distances[i] << ") ";
    }
    cout << "\n";
    
    // Componentes conexos
    ConnectedComponents cc(gt.adj);
    int numCC = cc.find_components();
    cout << "Número de componentes conexos: " << numCC << "\n";
}

// ==================== Exemplo 5: Dijkstra ====================
void exemplo_dijkstra() {
    cout << "\n=== EXEMPLO: Dijkstra ===\n";
    int n = 5;
    ShortestPaths sp(n);
    
    // Grafo com pesos
    sp.add_edge(0, 1, 4);
    sp.add_edge(0, 2, 1);
    sp.add_edge(2, 1, 2);
    sp.add_edge(1, 3, 1);
    sp.add_edge(2, 3, 5);
    sp.add_edge(3, 4, 3);
    
    sp.dijkstra_lazy(0);
    
    cout << "Distâncias a partir do vértice 0:\n";
    for(int i = 0; i < n; i++) {
        cout << "  Para " << i << ": " << sp.get_distance(i) << "\n";
    }
}

// ==================== Exemplo 6: MST - Kruskal ====================
void exemplo_kruskal() {
    cout << "\n=== EXEMPLO: MST - Kruskal ===\n";
    int n = 4;
    vector<pair<int, ii>> edges;
    
    // {peso, {u, v}}
    edges.pb({1, {0, 1}});
    edges.pb({2, {1, 2}});
    edges.pb({3, {2, 3}});
    edges.pb({4, {0, 2}});
    edges.pb({5, {1, 3}});
    
    MST mst(edges, n);
    int cost = mst.kruskal();
    
    cout << "Custo da MST: " << cost << "\n";
}

// ==================== Exemplo 7: Knapsack ====================
void exemplo_knapsack() {
    cout << "\n=== EXEMPLO: Knapsack 0/1 ===\n";
    vi weights = {2, 3, 4, 5};
    vi values = {3, 4, 5, 6};
    int capacity = 8;
    
    int maxValue = Knapsack::knapsack_01(capacity, weights, values, 4);
    cout << "Capacidade: " << capacity << "\n";
    cout << "Valor máximo: " << maxValue << "\n";
    
    auto [value, items] = Knapsack::knapsack_with_items(capacity, weights, values, 4);
    cout << "Itens incluídos (índices): ";
    for(int i : items) cout << i << " ";
    cout << "\n";
}

// ==================== Exemplo 8: LCS ====================
void exemplo_lcs() {
    cout << "\n=== EXEMPLO: Longest Common Subsequence ===\n";
    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    
    int length = LCS::lcs_length(s1, s2);
    string lcs = LCS::lcs_string(s1, s2);
    
    cout << "String 1: " << s1 << "\n";
    cout << "String 2: " << s2 << "\n";
    cout << "Tamanho da LCS: " << length << "\n";
    cout << "LCS: " << lcs << "\n";
}

// ==================== Exemplo 9: LIS ====================
void exemplo_lis() {
    cout << "\n=== EXEMPLO: Longest Increasing Subsequence ===\n";
    vi arr = {10, 9, 2, 5, 3, 7, 101, 18};
    
    cout << "Array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";
    
    int lis1 = LIS::lis_dp(arr);
    int lis2 = LIS::lis_binary_search(arr);
    
    cout << "LIS (O(n²)): " << lis1 << "\n";
    cout << "LIS (O(n log n)): " << lis2 << "\n";
}

// ==================== Exemplo 10: Coin Change ====================
void exemplo_coin_change() {
    cout << "\n=== EXEMPLO: Coin Change ===\n";
    vi coins = {1, 5, 10, 25};
    int amount = 30;
    
    int minCoins = CoinChange::min_coins(coins, amount);
    int ways = CoinChange::count_ways(coins, amount);
    
    cout << "Moedas disponíveis: 1, 5, 10, 25\n";
    cout << "Valor: " << amount << "\n";
    cout << "Número mínimo de moedas: " << minCoins << "\n";
    cout << "Número de maneiras: " << ways << "\n";
}

// ==================== Exemplo 11: Topological Sort ====================
void exemplo_topological_sort() {
    cout << "\n=== EXEMPLO: Topological Sort ===\n";
    int n = 6;
    vvi adj(n);
    
    // DAG: 5->2->3->1, 4->0->1, 4->1
    adj[5].pb(2);
    adj[2].pb(3);
    adj[3].pb(1);
    adj[4].pb(0);
    adj[0].pb(1);
    adj[4].pb(1);
    
    TopologicalSort ts(adj);
    
    // Kahn's algorithm
    vi kahn_result = ts.kahn_algorithm();
    cout << "Kahn's Algorithm: ";
    for(int v : kahn_result) cout << v << " ";
    cout << "\n";
    
    // DFS-based
    vi dfs_result = ts.dfs_topological_sort();
    cout << "DFS-based: ";
    for(int v : dfs_result) cout << v << " ";
    cout << "\n";
    
    cout << "Tem ciclo? " << (ts.has_cycle() ? "Sim" : "Não") << "\n";
}

// ==================== Exemplo 12: Bipartite Graph ====================
void exemplo_bipartite_graph() {
    cout << "\n=== EXEMPLO: Bipartite Graph ===\n";
    int n = 4;
    vvi adj(n);
    
    // Grafo bipartido: 0-1, 0-3, 2-1, 2-3
    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};
    
    BipartiteGraph bg(adj);
    bool is_bip = bg.check_bipartite();
    cout << "É bipartido? " << (is_bip ? "Sim" : "Não") << "\n";
    
    if(is_bip) {
        auto [set1, set2] = bg.get_partition();
        cout << "Conjunto 1: ";
        for(int v : set1) cout << v << " ";
        cout << "\nConjunto 2: ";
        for(int v : set2) cout << v << " ";
        cout << "\n";
    }
}

// ==================== Exemplo 13: Articulation Points e Bridges ====================
void exemplo_articulation_bridges() {
    cout << "\n=== EXEMPLO: Articulation Points & Bridges ===\n";
    int n = 7;
    vvi adj(n);
    
    // Grafo com pontos de articulação
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4, 5};
    adj[4] = {3, 5};
    adj[5] = {3, 4, 6};
    adj[6] = {5};
    
    ArticulationPointsBridges apb(adj);
    apb.find_articulation_points_and_bridges();
    
    vi art_points = apb.get_articulation_points();
    cout << "Pontos de articulação: ";
    for(int v : art_points) cout << v << " ";
    cout << "\n";
    
    vii bridges = apb.get_bridges();
    cout << "Pontes: ";
    for(auto [u, v] : bridges) cout << "(" << u << "," << v << ") ";
    cout << "\n";
}

// ==================== Exemplo 14: Strongly Connected Components ====================
void exemplo_strongly_connected() {
    cout << "\n=== EXEMPLO: Strongly Connected Components ===\n";
    int n = 5;
    vvi adj(n);
    
    // Grafo direcionado com SCCs
    adj[0] = {1};
    adj[1] = {2, 3};
    adj[2] = {0};
    adj[3] = {4};
    adj[4] = {};
    
    StronglyConnectedComponents scc(adj);
    scc.find_sccs();
    
    cout << "Número de SCCs: " << scc.get_scc_count() << "\n";
    
    vi scc_ids = scc.get_scc_ids();
    cout << "SCC de cada vértice: ";
    for(int i = 0; i < n; i++) {
        cout << "(" << i << ":" << scc_ids[i] << ") ";
    }
    cout << "\n";
}

// ==================== Main ====================
int main() {
    cout << "╔════════════════════════════════════════════════════╗\n";
    cout << "║  BIBLIOTECA DE PROGRAMAÇÃO COMPETITIVA - EXEMPLOS ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    
    exemplo_segment_tree();
    exemplo_fenwick_tree();
    exemplo_union_find();
    exemplo_graph_traversal();
    exemplo_topological_sort();
    exemplo_bipartite_graph();
    exemplo_articulation_bridges();
    exemplo_strongly_connected();
    exemplo_dijkstra();
    exemplo_kruskal();
    exemplo_knapsack();
    exemplo_lcs();
    exemplo_lis();
    exemplo_coin_change();
    
    cout << "\n╔════════════════════════════════════════════════════╗\n";
    cout << "║              FIM DOS EXEMPLOS                      ║\n";
    cout << "╚════════════════════════════════════════════════════╝\n";
    
    return 0;
}
