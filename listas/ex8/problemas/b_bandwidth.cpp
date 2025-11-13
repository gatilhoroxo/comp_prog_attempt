/*
PROBLEMA B - BANDWIDTH (LARGURA DE BANDA MÁXIMA)

ANÁLISE DO PROBLEMA:
- Rede de computadores com conexões que têm capacidade de largura de banda
- Encontrar máxima largura de banda total entre dois nós
- Dados podem ser transmitidos simultaneamente por múltiplos caminhos
- Clássico problema de Maximum Flow (fluxo máximo)

ESTRATÉGIA DE SOLUÇÃO:
1. Modelar como problema de fluxo máximo em rede
2. Nós da rede = vértices do grafo
3. Conexões = arestas com capacidade = largura de banda
4. Usar algoritmo Ford-Fulkerson ou Dinic para encontrar fluxo máximo
5. Fluxo máximo = largura de banda máxima entre origem e destino

ALGORITMOS NECESSÁRIOS:
- Maximum Flow: Ford-Fulkerson, Edmonds-Karp, ou Dinic
- BFS para encontrar augmenting paths (Edmonds-Karp)
- DFS para encontrar paths (Ford-Fulkerson)

PASSOS PARA IMPLEMENTAR:
1. Ler especificação da rede: n nós, origem s, destino t, c conexões
2. Construir grafo com capacidades (conexões bidirecionais)
3. Executar algoritmo de fluxo máximo de s para t
4. Imprimir resultado no formato especificado

ESTRUTURAS DE DADOS:
- Matriz de capacidade ou vector de adjacência com capacidades
- Matriz residual para algoritmo de fluxo
- Array de parent para reconstruir caminhos (BFS)

COMPLEXIDADE:
- Ford-Fulkerson: O(E * max_flow) - pode ser lento
- Edmonds-Karp: O(V * E²) - melhor garantia
- Dinic: O(V² * E) - mais eficiente

DICAS:
- Use Edmonds-Karp (BFS) para garantir complexidade polinomial
- Conexões são bidirecionais: adicionar capacidade nos dois sentidos
- Podem haver múltiplas conexões entre mesmo par de nós: somar capacidades
- Implementar grafo residual corretamente

ALGORITMO EDMONDS-KARP:
1. Enquanto existe caminho de s para t no grafo residual:
   - Usar BFS para encontrar caminho de s para t
   - Encontrar capacidade mínima no caminho (bottleneck)
   - Atualizar capacidades residuais ao longo do caminho
   - Adicionar bottleneck ao fluxo total
2. Retornar fluxo total

GRAFO RESIDUAL:
- Para cada aresta u → v com capacidade c:
  - Capacidade residual forward: c - fluxo_atual
  - Capacidade residual backward: fluxo_atual
- Permite "desfazer" fluxo se necessário
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    int network_num = 1;
    int n;
    
    // Ler até encontrar 0
    while(cin >> n && n != 0) {
        
        // 1. Ler s, t, c
        
        // 2. Construir grafo com capacidades:
        //    - Ler c conexões
        //    - Adicionar capacidade bidirecional
        //    - Somar se múltiplas conexões entre mesmo par
        
        // 3. Executar algoritmo de fluxo máximo (Edmonds-Karp):
        //    - BFS para encontrar augmenting paths
        //    - Atualizar grafo residual
        //    - Somar fluxos até não haver mais paths
        
        // 4. Imprimir resultado no formato correto
        
        cout << "Network " << network_num++ << endl;
        // cout << "The bandwidth is " << max_flow << "." << endl << endl;
    }
    
    return 0;
}