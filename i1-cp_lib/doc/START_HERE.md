# 🎯 Biblioteca de Programação Competitiva - Início

## 📚 Bem-vindo!

Esta é uma biblioteca organizada de algoritmos e estruturas de dados para programação competitiva.

## 🚀 Comece Aqui

### Se é sua primeira vez:
1. Leia **[GUIDE.md](GUIDE.md)** - Guia completo da biblioteca
2. Leia **[README.md](README.md)** - Documentação detalhada
3. Execute **[examples.cpp](examples.cpp)** - Veja exemplos funcionando

### Durante uma competição:
1. **[INDEX.md](INDEX.md)** - Encontre algoritmo por tipo de problema
2. **[TIPSSHEET.cpp](TIPSSHEET.cpp)** - Referência rápida de sintaxe

### Para visualizar estrutura:
- **[STRUCTURE.md](STRUCTURE.md)** - Diagramas e árvores de decisão

---

## 📦 Arquivos da Biblioteca

### ✨ Principais (Use estes!)

| Arquivo | Conteúdo |
|---------|----------|
| **[cp_lib.hpp](cp_lib.hpp)** | Typedefs, constantes, macros - INCLUIR SEMPRE PRIMEIRO |
| **[data_structures.hpp](data_structures.hpp)** | Segment Tree, Fenwick Tree, Union-Find |
| **[graphs.hpp](graphs.hpp)** | DFS, BFS, componentes, ordenação topológica, bipartição |
| **[shortest_paths.hpp](shortest_paths.hpp)** | Dijkstra, Bellman-Ford, Floyd-Warshall |
| **[mst.hpp](mst.hpp)** | Kruskal, Prim, MST |
| **[dynamic_programming.hpp](dynamic_programming.hpp)** | Knapsack, LCS, LIS, Coin Change, etc |

### 📖 Documentação

| Arquivo | Descrição |
|---------|-----------|
| **[GUIDE.md](GUIDE.md)** | 📘 Guia completo - COMECE AQUI |
| **[README.md](README.md)** | 📚 Documentação detalhada de cada módulo |
| **[INDEX.md](INDEX.md)** | 🔍 Índice rápido por tipo de problema |
| **[TIPSSHEET.cpp](TIPSSHEET.cpp)** | ⚡ Referência rápida de sintaxe |
| **[STRUCTURE.md](STRUCTURE.md)** | 📊 Visualização e diagramas |
| **[examples.cpp](examples.cpp)** | 💻 Exemplos práticos de uso |

---

## 🎯 Índice Rápido

### Por Categoria

- **Estruturas de Dados** → [data_structures.hpp](data_structures.hpp)
  - Segment Tree, Fenwick Tree, Union-Find

- **Grafos** → [graphs.hpp](graphs.hpp)
  - DFS, BFS, Componentes, Topological Sort, Bipartição, Flood Fill

- **Caminhos Mínimos** → [shortest_paths.hpp](shortest_paths.hpp)
  - Dijkstra, Bellman-Ford, Floyd-Warshall

- **MST** → [mst.hpp](mst.hpp)
  - Kruskal, Prim

- **Programação Dinâmica** → [dynamic_programming.hpp](dynamic_programming.hpp)
  - Knapsack, LCS, LIS, Edit Distance, Coin Change

### Por Problema Comum

| Problema | Solução | Arquivo |
|----------|---------|---------|
| Range Minimum Query | `SegmentTree` | [data_structures.hpp](data_structures.hpp) |
| Range Sum Query | `FenwickTree` | [data_structures.hpp](data_structures.hpp) |
| Conjuntos Disjuntos | `UnionFind` | [data_structures.hpp](data_structures.hpp) |
| Componentes Conexos | `GraphUtils::count_connected_components()` | [graphs.hpp](graphs.hpp) |
| Menor Caminho | `ShortestPaths::dijkstra_lazy()` | [shortest_paths.hpp](shortest_paths.hpp) |
| Conectar com Custo Mín | `MST::kruskal()` | [mst.hpp](mst.hpp) |
| Mochila | `Knapsack::knapsack_01()` | [dynamic_programming.hpp](dynamic_programming.hpp) |

---

## 💻 Exemplo de Uso

```cpp
#include <bits/stdc++.h>
using namespace std;

// Copie typedefs necessários de cp_lib.hpp
using vi = vector<int>;
using ii = pair<int,int>;

// Cole a classe que precisa aqui
class SegmentTree {
    // ... código da classe
};

int main() {
    // Seu código
    vi arr = {3, 2, 4, 5, 1};
    SegmentTree st(arr);
    cout << st.rmq(1, 4) << '\n';
    return 0;
}
```

---

## 🎓 Como Usar Esta Biblioteca

### 1. Durante Estudo
1. Compile e execute `examples.cpp` para ver tudo funcionando
2. Leia `README.md` para entender cada algoritmo
3. Pratique problemas usando a biblioteca

### 2. Durante Competição
1. Identifique o tipo de problema
2. Consulte `INDEX.md` para encontrar o algoritmo
3. Abra o arquivo `.hpp` correspondente
4. Copie a classe + typedefs necessários
5. Cole no seu código e adapte

### 3. Precisa de Sintaxe Rápida?
Abra `TIPSSHEET.cpp` - tem exemplos prontos de uso

---

## 📊 Estrutura Visual

```
BIBLIOTECA
│
├── 🟢 INCLUDE SEMPRE PRIMEIRO
│   └── cp_lib.hpp
│
├── 🔵 MÓDULOS PRINCIPAIS
│   ├── data_structures.hpp
│   ├── graphs.hpp
│   ├── shortest_paths.hpp
│   ├── mst.hpp
│   └── dynamic_programming.hpp
│
└── 📚 DOCUMENTAÇÃO
    ├── GUIDE.md         ← Comece aqui!
    ├── README.md        ← Documentação completa
    ├── INDEX.md         ← Busca rápida
    ├── TIPSSHEET.cpp   ← Sintaxe rápida
    ├── STRUCTURE.md     ← Visualizações
    └── examples.cpp     ← Código funcionando
```

---

## ⚡ Quick Start - 3 Passos

### Passo 1: Entenda a biblioteca
```bash
# Leia o guia completo
cat GUIDE.md
```

### Passo 2: Veja funcionando
```bash
# Compile e execute exemplos
g++ -std=c++17 examples.cpp -o examples
./examples
```

### Passo 3: Use em competição
```
1. Abra INDEX.md
2. Encontre seu algoritmo
3. Copie da .hpp correspondente
4. Resolva o problema!
```

---

## 🔧 Requisitos

- C++11 ou superior
- Compilador: g++, clang++, ou similar
- Conhecimento básico de C++ e algoritmos

---

## 📝 Compilando Exemplos

```bash
# Compilar examples.cpp
g++ -std=c++17 examples.cpp -o examples

# Executar
./examples
```

---

## 🎯 Fluxograma de Uso

```
PROBLEMA
   ↓
Ler enunciado
   ↓
Identificar técnica ──→ Dúvida? ──→ Consulte INDEX.md
   ↓
Abrir arquivo .hpp
   ↓
Copiar classe + typedefs
   ↓
Adaptar se necessário
   ↓
Testar com exemplos
   ↓
SUBMETER! 🎉
```

---

## 💡 Dicas

- ✅ Sempre inclua `cp_lib.hpp` primeiro
- ✅ Teste com exemplos antes de submeter
- ✅ Verifique complexidade vs limites do problema
- ✅ Use `TIPSSHEET.cpp` para sintaxe rápida
- ✅ Consulte `INDEX.md` quando tiver dúvida

---

## 📞 Navegação Rápida

| Quero... | Vá para... |
|----------|------------|
| Aprender a usar | [GUIDE.md](GUIDE.md) |
| Ver documentação completa | [README.md](README.md) |
| Encontrar algoritmo | [INDEX.md](INDEX.md) |
| Ver sintaxe rápida | [TIPSSHEET.cpp](TIPSSHEET.cpp) |
| Ver diagramas | [STRUCTURE.md](STRUCTURE.md) |
| Ver código funcionando | [examples.cpp](examples.cpp) |

---

## 🏆 Conteúdo da Biblioteca

### Estruturas de Dados
- Segment Tree (RMQ)
- Fenwick Tree (BIT)
- Union-Find (DSU)

### Grafos
- DFS, BFS
- Componentes Conexos
- Ordenação Topológica
- Grafo Bipartido
- Flood Fill
- Pontos de Articulação & Pontes
- Componentes Fortemente Conexos (Tarjan)

### Caminhos Mínimos
- Dijkstra
- Bellman-Ford
- Floyd-Warshall
- Variações (Warshall, minimax, maximin)

### MST
- Kruskal
- Prim
- Second Best MST

### Programação Dinâmica
- Knapsack (0/1 e Unbounded)
- Longest Common Subsequence (LCS)
- Longest Increasing Subsequence (LIS)
- Edit Distance
- Coin Change
- Matrix Chain Multiplication

---

## 🎉 Comece Agora!

1. **Primeira vez?** → Leia [GUIDE.md](GUIDE.md)
2. **Já conhece?** → Use [INDEX.md](INDEX.md) para buscar
3. **Competindo?** → [TIPSSHEET.cpp](TIPSSHEET.cpp) é seu amigo

---

**Boa sorte nas competições! 🚀**

*Versão 1.0 - Novembro 2025*
