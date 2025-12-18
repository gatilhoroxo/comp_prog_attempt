// ==================== TIPS SHEET - REFERÊNCIA RÁPIDA ====================
// Use este arquivo como referência rápida durante competições

// ==================== DICAS RÁPIDAS ====================
/*

1. LEIA O PROBLEMA COM ATENÇÃO
   - Identifique: entrada/saída, limites, casos especiais

2. ESCOLHA A ESTRUTURA CERTA
   - n ≤ 10: força bruta, recursão, backtracking
   - n ≤ 20: bitmask DP, meet-in-the-middle
   - n ≤ 100: O(n³) - Floyd-Warshall, DP cúbico
   - n ≤ 1000: O(n²) - DP quadrático, bubble sort
   - n ≤ 10^5: O(n log n) - sort, segment tree, dijkstra
   - n ≤ 10^6: O(n) - linear scan, hash table
   - n ≤ 10^9: O(log n) - busca binária, modular exponentiation

3. GRAFOS
   - Não direcionado + conectividade → DFS/BFS ou Union-Find
   - Caminho mínimo sem peso → BFS
   - Caminho mínimo com peso positivo → Dijkstra
   - Caminho mínimo com peso negativo → Bellman-Ford
   - Todos os pares → Floyd-Warshall
   - DAG → Ordenação topológica + DP
   - MST → Kruskal ou Prim
   - Pontos críticos → Articulation points
   - SCCs → Tarjan ou Kosaraju

4. DP
   - Identifique subproblemas sobrepostos
   - Defina estado (o que varia?)
   - Defina transição (como calcular?)
   - Defina caso base
   - Implemente top-down (memoização) ou bottom-up

5. OTIMIZAÇÃO
   - Use ios_base::sync_with_stdio(false); cin.tie(NULL);
   - Evite endl, use '\n'
   - Use referências em loops: for(auto& x : v)
   - Pré-calcule o que for possível
   - Use estruturas apropriadas (vector vs set vs map)

6. DEBUG
   - Teste casos pequenos manualmente
   - Teste casos extremos (0, 1, máximo)
   - Imprima variáveis intermediárias
   - Verifique overflow (use long long se necessário)
   - Verifique indexação (0-based vs 1-based)

7. ANTES DE SUBMETER
   - Leia o problema novamente
   - Verifique limites e tipos de dados
   - Teste todos os exemplos
   - Pense em casos especiais
   - Revise o código

*/

// ==================== COMPLEXIDADES COMUNS ====================
/*
O(1)         : Array access, hash table lookup
O(log n)     : Binary search, balanced BST operations
O(n)         : Linear search, single loop
O(n log n)   : Merge sort, heap sort, efficient sorting
O(n²)        : Bubble sort, selection sort, nested loops
O(n³)        : Floyd-Warshall, naive matrix multiplication
O(2^n)       : Subsets generation, naive recursion
O(n!)        : Permutations generation
*/

// ==================== COMPARAÇÃO DE ESTRUTURAS ====================
/*
QUANDO USAR CADA UMA:

vector<int>
  - Acesso por índice O(1)
  - Inserção no final O(1) amortizado
  - Busca O(n)
  ✓ Use quando precisar de acesso rápido por índice

set<int>
  - Inserção/remoção/busca O(log n)
  - Mantém elementos ordenados e únicos
  ✓ Use quando precisar de ordem + unicidade

unordered_set<int>
  - Inserção/remoção/busca O(1) médio
  - Sem ordem, elementos únicos
  ✓ Use quando precisar apenas unicidade

map<K,V>
  - Acesso/inserção/remoção O(log n)
  - Mantém chaves ordenadas
  ✓ Use quando precisar de mapeamento + ordem

unordered_map<K,V>
  - Acesso/inserção/remoção O(1) médio
  - Sem ordem nas chaves
  ✓ Use quando precisar apenas mapeamento

priority_queue<int>
  - Inserção O(log n)
  - Acesso ao máximo O(1)
  - Remoção do máximo O(log n)
  ✓ Use para heap/fila de prioridade

deque<int>
  - Inserção/remoção nas pontas O(1)
  - Acesso por índice O(1)
  ✓ Use quando precisar de fila dupla

queue<int>
  - Inserção no final O(1)
  - Remoção no início O(1)
  ✓ Use para BFS, processamento FIFO

stack<int>
  - Push/pop O(1)
  ✓ Use para DFS, processamento LIFO
*/

// #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
// #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#
// #-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#

// ==================== SEGMENT TREE ====================
/*
vi arr = {3, 2, 4, 5, 1};
SegmentTree st(arr);
int min_val = st.rmq(1, 4);    // Mínimo no intervalo [1, 4] (1-indexed)
st.modify(3, 10);              // Muda arr[3] para 10 (1-indexed)
*/

// ==================== FENWICK TREE ====================
/*
FenwickTree ft(n);
ft.adjust(i, v);               // Adiciona v ao índice i
int sum = ft.rsq(a, b);        // Soma do intervalo [a, b]
int sum_prefix = ft.rsq(k);    // Soma [1, k]
*/

// ==================== UNION-FIND ====================
/*
UnionFind uf(n);
uf.unionSet(u, v);             // Une conjuntos de u e v
bool same = uf.isSameSet(u, v);// Verifica se u e v estão no mesmo conjunto
int root = uf.findSet(u);      // Retorna representante do conjunto de u
*/

// ==================== GRAPH UTILS ====================
/*
// Inicialização
vvi adj(n);                    // Lista de adjacência simples
vvii adjW(n);                  // Lista com pesos: vector<pair<int,int>>
GraphUtils g(adj);

// DFS
vi visited(n, UNVISITED);
g.dfs_list(visited, start);

// BFS
vi visited(n, UNVISITED);
g.bfs(visited, start);

// Componentes conexos
int numCC = g.count_connected_components();

// Ordenação topológica
vi topo = g.get_topological_sort();

// Bipartição
bool isBi = g.is_bipartite();
*/

// ==================== FLOOD FILL ====================
/*
vvi grid(R, vi(C));
FloodFill ff(R, C, grid);
int size = ff.fill(r, c, old_color, new_color);
*/

// ==================== ARTICULATION POINTS & BRIDGES ====================
/*
vvii adj(n);
GraphAlgorithms ga(adj);
ga.find_articulation_points_and_bridges();
// Acesse ga.articulation_vertex[i] e ga.bridge_vertex
*/

// ==================== STRONGLY CONNECTED COMPONENTS (Tarjan) ====================
/*
vvii adj(n);
GraphAlgorithms ga(adj);
ga.find_strongly_connected_components();
*/

// ==================== DIJKSTRA ====================
/*
ShortestPaths sp(n);
sp.add_edge(u, v, weight);
sp.dijkstra_lazy(source);
int dist = sp.get_distance(target);
vi all_dists = sp.get_distances();
*/

// ==================== BELLMAN-FORD ====================
/*
ShortestPaths sp(n);
sp.add_edge(u, v, weight);
sp.bellman_ford(source);
bool has_neg = sp.has_negative_cycle(source);
*/

// ==================== FLOYD-WARSHALL ====================
/*
ShortestPaths sp(n);
// Adicionar arestas...
vvi D(n, vi(n));
sp.floyd_warshall(D);
// D[i][j] = distância de i para j
*/

// ==================== KRUSKAL ====================
/*
vector<pair<int, ii>> edges;   // {peso, {u, v}}
edges.pb({weight, {u, v}});
MST mst(edges, n);
int cost = mst.kruskal();

// Com arestas da MST
auto [cost, mst_edges] = mst.kruskal_with_edges();
*/

// ==================== PRIM ====================
/*
vvii adj(n);                   // {vizinho, peso}
adj[u].pb({v, weight});
MST mst(adj, n);
int cost = mst.prim(start_vertex);
*/

// ==================== KNAPSACK 0/1 ====================
/*
vi weights = {2, 3, 4, 5};
vi values = {3, 4, 5, 6};
int capacity = 8;
int max_val = Knapsack::knapsack_01(capacity, weights, values, n);

// Com itens incluídos
auto [value, items] = Knapsack::knapsack_with_items(capacity, weights, values, n);
*/

// ==================== KNAPSACK UNBOUNDED ====================
/*
vi weights, values;
int capacity;
int max_val = Knapsack::unbounded_knapsack(capacity, weights, values, n);
*/

// ==================== LCS ====================
/*
string s1, s2;
int length = LCS::lcs_length(s1, s2);
string lcs_str = LCS::lcs_string(s1, s2);
*/

// ==================== LIS ====================
/*
vi arr;
int lis_len = LIS::lis_binary_search(arr);  // O(n log n) - RECOMENDADO
// ou
int lis_len = LIS::lis_dp(arr);             // O(n²)
*/

// ==================== EDIT DISTANCE ====================
/*
string s1, s2;
int dist = EditDistance::min_edit_distance(s1, s2);
*/

// ==================== COIN CHANGE ====================
/*
vi coins = {1, 5, 10, 25};
int amount = 30;

// Número mínimo de moedas
int min_coins = CoinChange::min_coins(coins, amount);

// Número de maneiras diferentes
int ways = CoinChange::count_ways(coins, amount);
*/

// ==================== MATRIX CHAIN MULTIPLICATION ====================
/*
vi dimensions;  // [d0, d1, d2, ..., dn] onde matriz i é (di-1 x di)
int min_mult = MatrixChain::min_multiplications(dimensions);
*/

