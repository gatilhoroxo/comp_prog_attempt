# 📚 Biblioteca de Programação Competitiva

Biblioteca organizada de algoritmos e estruturas de dados para competições de programação.

## 📁 Estrutura da Biblioteca

```
lib/
├── cp_lib.hpp              # Definições centrais, typedefs e includes
├── data_structures.hpp     # Estruturas de dados
├── graphs.hpp              # Algoritmos de grafos
├── shortest_paths.hpp      # Caminhos mínimos
├── mst.hpp                 # Árvore geradora mínima
└── dynamic_programming.hpp # Programação dinâmica
```

## 🚀 Como Usar

### Uso Básico

Para usar qualquer algoritmo, basta incluir o arquivo header correspondente:

```cpp
#include "cp_lib.hpp"           // Sempre incluir primeiro
#include "data_structures.hpp"  // Para Segment Tree, Fenwick Tree, etc
```

### Copiar e Colar

Cada classe é **independente e pronta para copiar**. Você pode:
1. Copiar apenas a classe que precisa
2. Incluir o header completo no seu código
3. Adaptar conforme necessário

---

## 📦 Módulos da Biblioteca

### 1️⃣ `cp_lib.hpp` - Definições Centrais

**O que tem:**
- Typedefs comuns (`vi`, `vii`, `ll`, etc)
- Constantes úteis (`INF`, `LINF`)
- Defines para DFS/BFS (`VISITED`, `UNVISITED`)
- Macros úteis (`pb`, `all`, `rep`, etc)

**Quando usar:**
- Incluir **SEMPRE** como primeiro header

---

### 2️⃣ `data_structures.hpp` - Estruturas de Dados

#### 🌲 **Segment Tree** (RMQ)
```cpp
vi arr = {3, 2, 4, 5, 1, 1, 5, 3};
SegmentTree st(arr);
cout << st.rmq(1, 5) << '\n';  // Mínimo no intervalo [1, 5]
st.modify(3, 10);               // Modifica posição 3 para 10
```

**Complexidade:** O(log n) por consulta/modificação

#### 📊 **Fenwick Tree** (BIT)
```cpp
FenwickTree ft(10);
ft.adjust(3, 5);        // Adiciona 5 na posição 3
cout << ft.rsq(1, 5);   // Soma no intervalo [1, 5]
```

**Complexidade:** O(log n) por operação

#### 🔗 **Union-Find** (DSU)
```cpp
UnionFind uf(n);
uf.unionSet(1, 2);
if(uf.isSameSet(1, 2)) {
    cout << "Estão conectados\n";
}
```

**Complexidade:** O(α(n)) ≈ O(1) amortizado

---

### 3️⃣ `graphs.hpp` - Algoritmos de Grafos

#### 🔍 **GraphUtils**
```cpp
vvi adj(n);  // Lista de adjacência
GraphUtils g(adj);

// DFS
vi visited(n, UNVISITED);
g.dfs_list(visited, 0);

// Componentes conexos
int numCC = g.count_connected_components();

// Ordenação topológica
vi topo = g.get_topological_sort();

// Verifica bipartição
if(g.is_bipartite()) {
    cout << "É bipartido!\n";
}
```

#### 🌊 **FloodFill**
```cpp
vvi grid(R, vi(C));
FloodFill ff(R, C, grid);
int size = ff.fill(0, 0, '.', '#');
```

#### 🔴 **GraphAlgorithms** (Pontos de Articulação & Tarjan)
```cpp
vvii adj(n);
GraphAlgorithms ga(adj);

// Pontos de articulação e pontes
ga.find_articulation_points_and_bridges();

// SCCs (Tarjan)
ga.find_strongly_connected_components();
```

---

### 4️⃣ `shortest_paths.hpp` - Caminhos Mínimos

#### 🚀 **ShortestPaths**

**Dijkstra (lazy deletion):**
```cpp
ShortestPaths sp(n);
sp.add_edge(0, 1, 5);
sp.dijkstra_lazy(0);
cout << sp.get_distance(4) << '\n';
```

**Bellman-Ford:**
```cpp
sp.bellman_ford(0);
if(sp.has_negative_cycle(0)) {
    cout << "Tem ciclo negativo!\n";
}
```

**Floyd-Warshall (APSP):**
```cpp
vvi D(n, vi(n));
sp.floyd_warshall(D);
// D[i][j] = menor caminho de i para j
```

**Variações:**
- `warshall(D)` - Transitive closure
- `minimax(D)` - Minimax path
- `maximin(D)` - Maximin path

---

### 5️⃣ `mst.hpp` - Árvore Geradora Mínima

#### 🌳 **MST**

**Kruskal:**
```cpp
vector<pair<int, ii>> edges;  // {peso, {u, v}}
MST mst(edges, n);
int cost = mst.kruskal();
```

**Prim:**
```cpp
vvii adj(n);  // {vizinho, peso}
MST mst(adj, n);
int cost = mst.prim(0);
```

**Com arestas da MST:**
```cpp
auto [cost, mst_edges] = mst.kruskal_with_edges();
```

**Second Best MST:**
```cpp
int second = mst.second_best_mst();
```

---

### 6️⃣ `dynamic_programming.hpp` - Programação Dinâmica

#### 🎒 **Knapsack**
```cpp
vi weights = {2, 3, 4, 5};
vi values = {3, 4, 5, 6};
int capacity = 5;

// 0/1 Knapsack
int maxValue = Knapsack::knapsack_01(capacity, weights, values, 4);

// Com itens incluídos
auto [value, items] = Knapsack::knapsack_with_items(capacity, weights, values, 4);

// Unbounded
int unbounded = Knapsack::unbounded_knapsack(capacity, weights, values, 4);
```

#### 📝 **LCS** (Longest Common Subsequence)
```cpp
string s1 = "ABCDGH", s2 = "AEDFHR";
int length = LCS::lcs_length(s1, s2);
string lcs = LCS::lcs_string(s1, s2);
```

#### 📈 **LIS** (Longest Increasing Subsequence)
```cpp
vi arr = {10, 9, 2, 5, 3, 7, 101, 18};

// O(n²)
int lis1 = LIS::lis_dp(arr);

// O(n log n)
int lis2 = LIS::lis_binary_search(arr);
```

#### ✏️ **Edit Distance**
```cpp
string s1 = "kitten", s2 = "sitting";
int dist = EditDistance::min_edit_distance(s1, s2);
```

#### 🪙 **Coin Change**
```cpp
vi coins = {1, 5, 10, 25};
int amount = 30;

// Número mínimo de moedas
int minCoins = CoinChange::min_coins(coins, amount);

// Número de maneiras
int ways = CoinChange::count_ways(coins, amount);
```

#### 🔢 **Matrix Chain Multiplication**
```cpp
vi dims = {10, 20, 30, 40, 30};
int minMult = MatrixChain::min_multiplications(dims);
```

---

## 💡 Dicas de Uso

### Durante uma Competição

1. **Identifique o tipo de problema**
2. **Copie a classe necessária** do arquivo correspondente
3. **Adapte se necessário** (mudar tipos, constantes, etc)
4. **Teste com exemplos** antes de submeter

### Estrutura Recomendada do Código

```cpp
#include <bits/stdc++.h>
using namespace std;

// Copie os typedefs de cp_lib.hpp
using ii = pair<int,int>;
using vi = vector<int>;
// ... outros necessários

// Cole a classe que você precisa aqui
class SegmentTree {
    // ... código da classe
};

int main() {
    // Seu código
    return 0;
}
```

---

## 📊 Tabela de Complexidades

| Estrutura/Algoritmo | Construção | Consulta | Modificação |
|---------------------|------------|----------|-------------|
| Segment Tree        | O(n)       | O(log n) | O(log n)    |
| Fenwick Tree        | O(n log n) | O(log n) | O(log n)    |
| Union-Find          | O(n)       | O(α(n))  | O(α(n))     |
| Dijkstra            | -          | O(E log V) | -         |
| Bellman-Ford        | -          | O(VE)    | -           |
| Floyd-Warshall      | -          | O(V³)    | -           |
| Kruskal             | -          | O(E log E) | -         |
| Prim                | -          | O(E log V) | -         |

---

## 🔧 Customização

Todos os algoritmos podem ser facilmente customizados:

- **Mudar tipo de dado:** Troque `int` por `ll` se necessário
- **Ajustar constantes:** Modifique `INF` conforme o problema
- **Adicionar funcionalidades:** As classes são extensíveis

---

## 📝 Observações Importantes

1. **Include guards:** Todos os headers têm `#ifndef` para evitar inclusões duplicadas
2. **Namespace:** Não usamos namespace próprio para facilitar cópia
3. **Comentários:** Explicam uso e complexidade de cada função
4. **Testado:** Estruturas foram testadas com exemplos básicos

---

## 🎯 Problemas Comuns e Soluções

### Problema: "Não compila ao incluir múltiplos headers"
**Solução:** Sempre inclua `cp_lib.hpp` primeiro

### Problema: "TLE (Time Limit Exceeded)"
**Solução:** Verifique a complexidade do algoritmo escolhido

### Problema: "WA (Wrong Answer) com Dijkstra"
**Solução:** Use Bellman-Ford se houver pesos negativos

---

## 📚 Referências

- Competitive Programming 3 (Halim & Halim)
- Introduction to Algorithms (CLRS)
- Codeforces, AtCoder, CSES Problem Set

---

**Boa sorte nas competições! 🚀**
