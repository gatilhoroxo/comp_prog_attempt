# 🗂️ Índice Rápido da Biblioteca

## 📍 Navegação Rápida por Problema

### Estruturas de Dados
| Problema | Arquivo | Classe | Complexidade |
|----------|---------|--------|--------------|
| Range Minimum Query (RMQ) | `data_structures.hpp` | `SegmentTree` | O(log n) |
| Range Sum Query (RSQ) | `data_structures.hpp` | `FenwickTree` | O(log n) |
| Conjuntos Disjuntos | `data_structures.hpp` | `UnionFind` | O(α(n)) |

### Grafos - Travessia
| Problema | Arquivo | Classe/Método | Complexidade |
|----------|---------|---------------|--------------|
| DFS | `graphs.hpp` | `GraphUtils::dfs_list()` | O(V+E) |
| BFS | `graphs.hpp` | `GraphUtils::bfs()` | O(V+E) |
| Componentes Conexos | `graphs.hpp` | `GraphUtils::count_connected_components()` | O(V+E) |
| Ordenação Topológica | `graphs.hpp` | `GraphUtils::get_topological_sort()` | O(V+E) |
| Grafo Bipartido | `graphs.hpp` | `GraphUtils::is_bipartite()` | O(V+E) |
| Flood Fill | `graphs.hpp` | `FloodFill::fill()` | O(R×C) |

### Grafos - Propriedades
| Problema | Arquivo | Classe/Método | Complexidade |
|----------|---------|---------------|--------------|
| Pontos de Articulação | `graphs.hpp` | `GraphAlgorithms::find_articulation_points_and_bridges()` | O(V+E) |
| Pontes | `graphs.hpp` | `GraphAlgorithms::find_articulation_points_and_bridges()` | O(V+E) |
| Componentes Fortemente Conexos | `graphs.hpp` | `GraphAlgorithms::find_strongly_connected_components()` | O(V+E) |

### Caminhos Mínimos
| Problema | Arquivo | Classe/Método | Complexidade |
|----------|---------|---------------|--------------|
| SSSP (pesos não-negativos) | `shortest_paths.hpp` | `ShortestPaths::dijkstra_lazy()` | O((V+E) log V) |
| SSSP (com pesos negativos) | `shortest_paths.hpp` | `ShortestPaths::bellman_ford()` | O(VE) |
| Detectar ciclo negativo | `shortest_paths.hpp` | `ShortestPaths::has_negative_cycle()` | O(VE) |
| APSP (All Pairs) | `shortest_paths.hpp` | `ShortestPaths::floyd_warshall()` | O(V³) |
| Transitive Closure | `shortest_paths.hpp` | `ShortestPaths::warshall()` | O(V³) |

### Árvore Geradora Mínima (MST)
| Problema | Arquivo | Classe/Método | Complexidade |
|----------|---------|---------------|--------------|
| MST - Kruskal | `mst.hpp` | `MST::kruskal()` | O(E log E) |
| MST - Prim | `mst.hpp` | `MST::prim()` | O(E log V) |
| Second Best MST | `mst.hpp` | `MST::second_best_mst()` | O(E² log E) |

### Programação Dinâmica
| Problema | Arquivo | Classe/Método | Complexidade |
|----------|---------|---------------|--------------|
| Knapsack 0/1 | `dynamic_programming.hpp` | `Knapsack::knapsack_01()` | O(nW) |
| Knapsack Ilimitado | `dynamic_programming.hpp` | `Knapsack::unbounded_knapsack()` | O(nW) |
| LCS (Longest Common Subseq) | `dynamic_programming.hpp` | `LCS::lcs_length()` | O(mn) |
| LIS (Longest Increasing Subseq) | `dynamic_programming.hpp` | `LIS::lis_binary_search()` | O(n log n) |
| Edit Distance | `dynamic_programming.hpp` | `EditDistance::min_edit_distance()` | O(mn) |
| Coin Change (min moedas) | `dynamic_programming.hpp` | `CoinChange::min_coins()` | O(n×amount) |
| Coin Change (contar maneiras) | `dynamic_programming.hpp` | `CoinChange::count_ways()` | O(n×amount) |
| Matrix Chain Multiplication | `dynamic_programming.hpp` | `MatrixChain::min_multiplications()` | O(n³) |

---

## 🎯 Encontrar Algoritmo por Tipo de Problema

### "Preciso consultar/atualizar intervalo em array"
→ `SegmentTree` ou `FenwickTree` em `data_structures.hpp`

### "Preciso saber se elementos estão conectados"
→ `UnionFind` em `data_structures.hpp`

### "Preciso visitar todos os nós do grafo"
→ `GraphUtils::dfs_list()` ou `bfs()` em `graphs.hpp`

### "Preciso encontrar componentes do grafo"
→ `GraphUtils::count_connected_components()` em `graphs.hpp`

### "Preciso ordenar tarefas com dependências"
→ `GraphUtils::get_topological_sort()` em `graphs.hpp`

### "Preciso saber se grafo pode ser 2-colorido"
→ `GraphUtils::is_bipartite()` em `graphs.hpp`

### "Preciso preencher região conectada"
→ `FloodFill` em `graphs.hpp`

### "Preciso encontrar vértices/arestas críticos"
→ `GraphAlgorithms::find_articulation_points_and_bridges()` em `graphs.hpp`

### "Preciso agrupar por conectividade forte (grafos direcionados)"
→ `GraphAlgorithms::find_strongly_connected_components()` em `graphs.hpp`

### "Preciso menor caminho de uma origem"
- Pesos não-negativos → `ShortestPaths::dijkstra_lazy()` em `shortest_paths.hpp`
- Pesos negativos → `ShortestPaths::bellman_ford()` em `shortest_paths.hpp`

### "Preciso menores caminhos entre todos os pares"
→ `ShortestPaths::floyd_warshall()` em `shortest_paths.hpp`

### "Preciso conectar todos os vértices com custo mínimo"
→ `MST::kruskal()` ou `MST::prim()` em `mst.hpp`

### "Preciso escolher itens com peso/valor"
→ `Knapsack` em `dynamic_programming.hpp`

### "Preciso maior subsequência comum"
→ `LCS` em `dynamic_programming.hpp`

### "Preciso maior subsequência crescente"
→ `LIS` em `dynamic_programming.hpp`

### "Preciso transformar uma string em outra"
→ `EditDistance` em `dynamic_programming.hpp`

### "Preciso formar valor com moedas"
→ `CoinChange` em `dynamic_programming.hpp`

---

## 📝 Template Básico para Competição

```cpp
#include <bits/stdc++.h>
using namespace std;

// Typedefs
using ii = pair<int,int>;
using vi = vector<int>;
using vii = vector<ii>;
using ll = long long;

// Constantes
const int INF = 1e9 + 7;
const int VISITED = 1;
const int UNVISITED = 0;

// Macros
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

// Cole aqui a classe que você precisa
// [CLASSE]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Seu código aqui
    
    return 0;
}
```

---

## 🔍 Checklist Rápido

Antes de escolher um algoritmo, pergunte:

- [ ] Qual é o tamanho da entrada? (n, m)
- [ ] Há limite de tempo? (TL)
- [ ] Grafo é direcionado ou não-direcionado?
- [ ] Arestas têm pesos? São negativos?
- [ ] Preciso de caminho único ou todos os caminhos?
- [ ] Há restrições especiais? (DAG, árvore, etc)

---

## 💾 Arquivos da Biblioteca

```
lib/
├── cp_lib.hpp              ← Sempre incluir primeiro
├── data_structures.hpp     ← Segment Tree, Fenwick, Union-Find
├── graphs.hpp              ← DFS, BFS, componentes, bipartição
├── shortest_paths.hpp      ← Dijkstra, Bellman-Ford, Floyd-Warshall
├── mst.hpp                 ← Kruskal, Prim
├── dynamic_programming.hpp ← Knapsack, LCS, LIS, etc
├── examples.cpp            ← Exemplos de uso
├── README.md               ← Documentação completa
└── INDEX.md                ← Este arquivo
```

---

## 🚀 Uso Rápido

1. Abra o arquivo correspondente ao tipo de problema
2. Localize a classe necessária
3. Copie a classe + typedefs necessários de `cp_lib.hpp`
4. Cole no seu código
5. Adapte se necessário

**Dica:** Use o arquivo `examples.cpp` para ver como usar cada classe!
