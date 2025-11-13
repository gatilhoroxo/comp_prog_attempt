/*
PROBLEMA C - SHORTEST PATH (CAMINHO MAIS CURTO)

ANÁLISE DO PROBLEMA:
- Grafo de servidores SMTP conectados por cabos
- Cada cabo tem latência (peso)
- Encontrar menor tempo para enviar mensagem de S para T
- Clássico problema de caminho mais curto

ESTRATÉGIA DE SOLUÇÃO:
1. Usar algoritmo de Dijkstra para encontrar caminho mais curto
2. Alternativa: Bellman-Ford se houver pesos negativos (não há neste caso)
3. Tratar caso onde T é inalcançável

ALGORITMOS NECESSÁRIOS:
- Dijkstra (caminho mais curto de fonte única)
- Representação de grafo com pesos

PASSOS PARA IMPLEMENTAR:
1. Ler número de casos
2. Para cada caso: ler n, m, S, T
3. Ler m arestas com pesos (bidirecionais)
4. Executar Dijkstra a partir de S
5. Verificar se T é alcançável e imprimir distância

ESTRUTURAS DE DADOS:
- Vector de adjacência com pesos: vector<vector<pair<int, int>>>
- Priority queue para Dijkstra
- Array de distâncias

COMPLEXIDADE:
- Tempo: O((V + E) log V) com Dijkstra
- Espaço: O(V + E)

DICAS:
- Use Dijkstra com priority queue (min heap)
- Inicialize distâncias com infinito
- Distância[S] = 0
- Se distância[T] ainda for infinito, é "unreachable"
- Lembre-se do formato de saída "Case #x: resultado"

IMPLEMENTAÇÃO DIJKSTRA:
1. dist[S] = 0, todos outros = INF  
2. Adicionar S na priority queue
3. Enquanto queue não vazia:
   - Pegar vértice u com menor distância
   - Para cada vizinho v de u:
     - Se dist[u] + peso(u,v) < dist[v]:
       - Atualizar dist[v]
       - Adicionar v na queue
*/

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler número de casos N
    
    // 2. Para cada caso:
    //    - Ler n, m, S, T
    //    - Construir grafo com m arestas
    //    - Executar Dijkstra de S
    //    - Imprimir resultado para T
    
    return 0;
}