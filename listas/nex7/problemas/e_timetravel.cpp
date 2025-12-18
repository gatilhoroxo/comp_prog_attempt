/*
PROBLEMA E - TIME TRAVEL (VIAGEM NO TEMPO)

ANÁLISE DO PROBLEMA:
- Grafo dirigido com pesos nas arestas (tempo de viagem)
- Possível voltar no tempo: se chegar em T' < T, pode voltar para T
- Encontrar menor tempo para ir de S para E
- Complicação: ciclos negativos podem permitir tempo negativo infinito

ESTRATÉGIA DE SOLUÇÃO:
1. Usar Bellman-Ford modificado para detectar ciclos negativos
2. Se há ciclo negativo alcançável de S e que pode alcançar E: retornar "?"
3. Caso contrário: retornar menor tempo encontrado

ALGORITMOS NECESSÁRIOS:
- Bellman-Ford (para detectar ciclos negativos)
- DFS/BFS (para verificar alcançabilidade)

PASSOS PARA IMPLEMENTAR:
1. Construir grafo dirigido
2. Executar Bellman-Ford de S para encontrar distâncias mínimas
3. Detectar ciclos negativos (se ainda há relaxamento na iteração V)
4. Para cada vértice em ciclo negativo, verificar se pode alcançar E
5. Se ciclo negativo pode alcançar E: retornar "?"
6. Senão: retornar distância mínima para E

ESTRUTURAS DE DADOS:
- Vector de adjacência dirigida
- Array de distâncias
- Array de marcação para ciclos negativos

COMPLEXIDADE:
- Tempo: O(VE) para Bellman-Ford + O(V+E) para verificar alcançabilidade
- Espaço: O(V + E)

DICAS:
- Bellman-Ford faz V-1 iterações normalmente
- Na V-ésima iteração, se ainda houver relaxamento = ciclo negativo
- Marque todos os vértices afetados por ciclos negativos
- Use DFS/BFS para verificar se vértices do ciclo negativo podem chegar em E
- Cuidado: ciclo negativo deve ser alcançável de S E poder alcançar E

ALGORITMO DETALHADO:
1. Inicializar dist[S] = 0, outros = INF
2. Relaxar arestas V-1 vezes (Bellman-Ford normal)
3. Verificar ciclos negativos: tentar relaxar mais uma vez
4. Para vértices que ainda relaxam: marcar como "ciclo negativo"
5. DFS a partir de cada vértice marcado para ver se alcança E
6. Se algum alcança E: retornar "?"
7. Senão: retornar dist[E] (ou "Impossible" se INF)

RELAXAMENTO:
- Para aresta u -> v com peso w:
- Se dist[u] + w < dist[v]: dist[v] = dist[u] + w
*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler parâmetros: n, m, S, E
    
    // 2. Construir grafo dirigido com m arestas
    
    // 3. Executar Bellman-Ford modificado:
    //    - V-1 iterações normais
    //    - V-ésima iteração para detectar ciclos negativos
    
    // 4. Verificar se ciclos negativos podem alcançar E
    
    // 5. Retornar "?", tempo mínimo, ou "Impossible"
    
    return 0;
}