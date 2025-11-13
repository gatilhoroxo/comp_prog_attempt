# 🗂️ GUIA COMPLETO DA BIBLIOTECA

## 📁 Arquivos da Biblioteca

### ✅ Arquivos Principais (USE ESTES!)

| Arquivo | Descrição | Status |
|---------|-----------|--------|
| `cp_lib.hpp` | Definições centrais, typedefs, macros | ✅ NOVO |
| `data_structures.hpp` | Segment Tree, Fenwick Tree, Union-Find | ✅ NOVO |
| `graphs.hpp` | Algoritmos de grafos (DFS, BFS, componentes, etc) | ✅ NOVO |
| `shortest_paths.hpp` | Dijkstra, Bellman-Ford, Floyd-Warshall | ✅ NOVO |
| `mst.hpp` | Kruskal, Prim, MST | ✅ NOVO |
| `dynamic_programming.hpp` | Knapsack, LCS, LIS, Coin Change, etc | ✅ NOVO |

### 📚 Arquivos de Referência

| Arquivo | Descrição |
|---------|-----------|
| `README.md` | Documentação completa com exemplos |
| `INDEX.md` | Índice rápido por tipo de problema |
| `TIPSSHEET.cpp` | Referência rápida de sintaxe |
| `STRUCTURE.md` | Visualização da estrutura |
| `examples.cpp` | Exemplos práticos de uso |
| `GUIDE.md` | Este arquivo |

### 🗄️ Arquivos Antigos (Manter para referência)

| Arquivo | Status | Substituto |
|---------|--------|------------|
| `defines.hpp` | ⚠️ Legado | Use `cp_lib.hpp` |
| `fenwick_tree.cpp` | ⚠️ Legado | Use `data_structures.hpp` |
| `union_find.cpp` | ⚠️ Legado | Use `data_structures.hpp` |
| `seg_tree.cpp` | ⚠️ Legado | Use `data_structures.hpp` |
| `graph.cpp` | ⚠️ Legado | Use `graphs.hpp`, `shortest_paths.hpp`, `mst.hpp` |
| `knapsack.cpp` | ⚠️ Legado | Use `dynamic_programming.hpp` |
| `lib.cpp` | ⚠️ Legado | Use `data_structures.hpp` |
| `teste.cpp` | ⚠️ Testes | Mantido para testes |

---

## 🚀 Início Rápido

### 1️⃣ Primeira vez usando?

Leia nesta ordem:
1. **`README.md`** - Visão geral e como usar cada módulo
2. **`INDEX.md`** - Encontrar algoritmo por tipo de problema
3. **`examples.cpp`** - Ver código funcionando

### 2️⃣ Durante uma competição?

1. Identifique o tipo de problema
2. Consulte **`INDEX.md`** para encontrar o algoritmo
3. Abra o arquivo `.hpp` correspondente
4. Copie a classe necessária + typedefs de `cp_lib.hpp`
5. Cole no seu código e adapte

### 3️⃣ Precisa de sintaxe rápida?

Abra **`TIPSSHEET.cpp`** - tem exemplos rápidos de uso

---

## 📖 Como Navegar na Biblioteca

### Por Tipo de Problema

```
Preciso de...                 → Veja arquivo...
─────────────────────────────────────────────────────────
Consultar intervalo           → data_structures.hpp
Conjuntos disjuntos           → data_structures.hpp
Travessia de grafo            → graphs.hpp
Componentes conexos           → graphs.hpp
Caminho mínimo                → shortest_paths.hpp
Árvore geradora mínima        → mst.hpp
Mochila / Subsequências       → dynamic_programming.hpp
```

### Por Algoritmo

```
Algoritmo                     → Arquivo
─────────────────────────────────────────────────────────
Segment Tree                  → data_structures.hpp
Fenwick Tree                  → data_structures.hpp
Union-Find / DSU              → data_structures.hpp
DFS / BFS                     → graphs.hpp
Componentes Conexos           → graphs.hpp
Ordenação Topológica          → graphs.hpp
Grafo Bipartido               → graphs.hpp
Flood Fill                    → graphs.hpp
Pontos de Articulação         → graphs.hpp
Componentes Fortemente Conexos→ graphs.hpp
Dijkstra                      → shortest_paths.hpp
Bellman-Ford                  → shortest_paths.hpp
Floyd-Warshall                → shortest_paths.hpp
Kruskal                       → mst.hpp
Prim                          → mst.hpp
Knapsack 0/1                  → dynamic_programming.hpp
Knapsack Unbounded            → dynamic_programming.hpp
LCS                           → dynamic_programming.hpp
LIS                           → dynamic_programming.hpp
Edit Distance                 → dynamic_programming.hpp
Coin Change                   → dynamic_programming.hpp
Matrix Chain Multiplication   → dynamic_programming.hpp
```

---

## 🎯 Workflow Recomendado

### Durante Estudo

```
1. Leia README.md para entender cada módulo
2. Execute examples.cpp para ver funcionando
3. Modifique examples.cpp para experimentar
4. Pratique problemas usando a biblioteca
```

### Durante Competição

```
1. Leia e entenda o problema
2. Identifique técnica necessária
3. Consulte INDEX.md
4. Copie classe do arquivo .hpp
5. Copie typedefs necessários de cp_lib.hpp
6. Adapte conforme necessário
7. Teste com exemplos
8. Submeta!
```

---

## 📊 Visão Geral dos Módulos

### 🔧 cp_lib.hpp
**O que tem:**
- Typedefs: `vi`, `vii`, `ll`, `ii`, etc
- Constantes: `INF`, `LINF`
- Macros: `pb`, `all`, `sz`, `rep`
- Defines para grafos: `VISITED`, `UNVISITED`

**Quando usar:** Sempre incluir primeiro em qualquer código

---

### 📦 data_structures.hpp
**O que tem:**
- `SegmentTree` - RMQ, modificações O(log n)
- `FenwickTree` - RSQ, atualizações O(log n)
- `UnionFind` - Conjuntos disjuntos O(α(n))

**Quando usar:** Consultas em intervalos, conjuntos disjuntos

---

### 🌐 graphs.hpp
**O que tem:**
- `GraphUtils` - DFS, BFS, componentes, topological sort, bipartição
- `FloodFill` - Preencher regiões em grid
- `GraphAlgorithms` - Pontos de articulação, pontes, Tarjan SCC

**Quando usar:** Qualquer problema de grafos não relacionado a caminhos mínimos ou MST

---

### 🛣️ shortest_paths.hpp
**O que tem:**
- `ShortestPaths` - Dijkstra, Bellman-Ford, Floyd-Warshall
- Variações: Warshall, minimax, maximin

**Quando usar:** Problemas de caminho mínimo

---

### 🌳 mst.hpp
**O que tem:**
- `MST` - Kruskal, Prim
- Second best MST

**Quando usar:** Conectar todos os vértices com custo mínimo

---

### 🎒 dynamic_programming.hpp
**O que tem:**
- `Knapsack` - 0/1, unbounded
- `LCS` - Longest Common Subsequence
- `LIS` - Longest Increasing Subsequence
- `EditDistance` - Levenshtein distance
- `CoinChange` - Problemas de moedas
- `MatrixChain` - Matrix chain multiplication

**Quando usar:** Problemas de otimização com subestrutura ótima

---

## 🔍 FAQ - Perguntas Frequentes

### Q: Qual arquivo devo incluir primeiro?
**A:** Sempre `cp_lib.hpp`

### Q: Posso incluir múltiplos arquivos?
**A:** Sim! Todos têm include guards para evitar duplicação.

### Q: Preciso incluir todos os arquivos?
**A:** Não! Inclua apenas o que você precisa.

### Q: Como copiar para um problema?
**A:** 
1. Copie typedefs de `cp_lib.hpp`
2. Copie a classe do arquivo correspondente
3. Cole no seu código

### Q: Os algoritmos estão testados?
**A:** Sim! Veja `teste.cpp` e `examples.cpp`

### Q: Posso modificar os algoritmos?
**A:** Sim! São templates, adapte conforme necessário.

### Q: Qual a diferença entre os arquivos antigos e novos?
**A:** Arquivos novos (`.hpp`) são organizados, documentados e prontos para competição. Antigos ficam para referência.

---

## 💡 Dicas Importantes

### ✅ DO (Faça)
- ✅ Sempre inclua `cp_lib.hpp` primeiro
- ✅ Teste com exemplos pequenos antes de submeter
- ✅ Leia os comentários no código
- ✅ Use `examples.cpp` para aprender
- ✅ Adapte conforme necessário
- ✅ Verifique complexidade antes de usar

### ❌ DON'T (Não faça)
- ❌ Não misture arquivos antigos com novos
- ❌ Não esqueça de copiar typedefs necessários
- ❌ Não use algoritmo sem entender complexidade
- ❌ Não submeta sem testar casos extremos

---

## 🎓 Recursos de Aprendizado

### Para aprender os algoritmos:
1. **Competitive Programming 3** (Halim & Halim)
2. **CLRS** (Introduction to Algorithms)
3. **CP-Algorithms** (cp-algorithms.com)

### Para praticar:
1. **Codeforces** (codeforces.com)
2. **AtCoder** (atcoder.jp)
3. **CSES Problem Set** (cses.fi/problemset)
4. **LeetCode** (leetcode.com)

---

## 📞 Estrutura de Suporte

```
📂 lib/
│
├── 🟢 ARQUIVOS PRINCIPAIS (Use durante competição)
│   ├── cp_lib.hpp
│   ├── data_structures.hpp
│   ├── graphs.hpp
│   ├── shortest_paths.hpp
│   ├── mst.hpp
│   └── dynamic_programming.hpp
│
├── 📘 DOCUMENTAÇÃO (Leia para aprender)
│   ├── README.md              ← Documentação completa
│   ├── INDEX.md               ← Índice por problema
│   ├── STRUCTURE.md           ← Visualização da estrutura
│   ├── TIPSSHEET.cpp         ← Referência rápida
│   ├── GUIDE.md               ← Este arquivo
│   └── examples.cpp           ← Exemplos práticos
│
└── ⚠️ LEGADO (Referência apenas)
    ├── defines.hpp
    ├── fenwick_tree.cpp
    ├── union_find.cpp
    ├── seg_tree.cpp
    ├── graph.cpp
    ├── knapsack.cpp
    ├── lib.cpp
    └── teste.cpp
```

---

## 🎯 Checklist para Competição

Antes de começar:
- [ ] Revisei `README.md` recentemente?
- [ ] Sei onde encontrar cada algoritmo?
- [ ] Testei a biblioteca compilando `examples.cpp`?

Durante o problema:
- [ ] Li o problema completamente?
- [ ] Identifiquei a técnica necessária?
- [ ] Consultei `INDEX.md` para encontrar algoritmo?
- [ ] Copiei todos os typedefs necessários?
- [ ] Verifiquei complexidade vs limites do problema?
- [ ] Testei com exemplos do problema?
- [ ] Testei casos extremos?

---

## 🏆 Boa Sorte!

Esta biblioteca contém tudo que você precisa para a maioria dos problemas de programação competitiva. Use-a com sabedoria e boas competições! 🚀

**Lembre-se:** Entender o algoritmo é mais importante que apenas copiar o código. Use esta biblioteca para aprender e praticar!

---

**Última atualização:** Novembro 2025
**Versão:** 1.0
**Autor:** Sua biblioteca organizada para CP
