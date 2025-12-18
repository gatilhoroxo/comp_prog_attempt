#ifndef GRAPHS_HPP
#define GRAPHS_HPP

// ==================== Biblioteca Modular de Grafos ====================
// Este arquivo inclui todos os módulos de algoritmos de grafos

#include "graph_traversal.hpp"  // DFS, BFS, componentes, topological sort
#include "graph_special.hpp"    // Bipartição, flood fill, coloração, caminhos eulerianos
#include "graph_advanced.hpp"   // Pontos críticos, SCCs, árvores, HLD
#include "graph_mst.hpp"              // Kruskal e Prim para encontrar MST
#include "graph_shortest_paths.hpp"   // Dijkstra, Bellman-Ford, Floyd-Warshall

// ================== Inclua apenas o que precisa ==================
// Para usar apenas um módulo específico, inclua diretamente:
// - #include "graph_traversal.hpp"  para DFS/BFS/componentes
// - #include "graph_special.hpp"    para problemas especiais
// - #include "graph_advanced.hpp"   para algoritmos avançados

// ==================== Classes Disponíveis ====================
/*

=== graph_traversal.hpp ===
- GraphTraversal         : DFS, BFS básicos
- ConnectedComponents    : Componentes conexos
- TopologicalSort        : Ordenação topológica (Kahn + DFS)
- CycleDetection         : Detecção de ciclos

=== graph_special.hpp ===  
- BipartiteGraph         : Verificação bipartida + matching
- FloodFill              : Preenchimento de regiões (grid)
- GraphColoring          : Coloração de grafos
- EulerianPath           : Caminhos e circuitos eulerianos
- MaximumIndependentSet  : Conjunto independente máximo

=== graph_advanced.hpp ===
- ArticulationPointsBridges    : Pontos de articulação e pontes
- StronglyConnectedComponents  : SCCs (Tarjan)
- TreeAlgorithms               : LCA, diâmetro, centroid decomposition
- HeavyLightDecomposition      : HLD para queries em árvores

=== mst.hpp ===
- Kruskal e Prim para encontrar MST

=== shortest_paths.hpp ===
- Dijkstra, Bellman-Ford, Floyd-Warshall


*/

#endif // GRAPHS_HPP
