/*
PROBLEMA C - CUT THE NETWORK (CORTAR A REDE)

ANÁLISE DO PROBLEMA:
- Rede de computadores conectando cidades
- Capital (cidade 1) e maior cidade (cidade 2) devem ser separadas
- Cada conexão tem custo de sabotagem
- Encontrar conjunto mínimo de conexões para cortar (min-cut)
- Minimizar custo total de sabotagem

ESTRATÉGIA DE SOLUÇÃO:
1. Problema de Minimum Cut em grafo
2. Encontrar min-cut entre cidade 1 e cidade 2
3. Min-cut = Max-flow (teorema de Ford-Fulkerson)
4. Usar algoritmo de fluxo máximo e reconstruir quais arestas foram saturadas
5. Essas arestas saturadas formam o min-cut

ALGORITMOS NECESSÁRIOS:
- Maximum Flow (Ford-Fulkerson, Edmonds-Karp, Dinic)
- Min-Cut reconstruction
- DFS/BFS para identificar componentes após remoção

PASSOS PARA IMPLEMENTAR:
1. Construir grafo com custos como capacidades
2. Executar max-flow de cidade 1 para cidade 2
3. Identificar arestas do min-cut:
   - Aresta (u,v) está no cut se: u alcançável de source e v não alcançável
   - Ou: capacidade residual (u,v) = 0 e u,v em componentes diferentes
4. Imprimir todas as arestas do min-cut

ESTRUTURAS DE DADOS:
- Grafo com capacidades (custos de sabotagem)
- Grafo residual após max-flow
- Array de visitados para DFS/BFS
- Lista de arestas originais para reconstrução

COMPLEXIDADE:
- Tempo: O(V²E) ou O(VE²) dependendo do algoritmo de fluxo
- Espaço: O(V + E)

DICAS:
- Após executar max-flow, fazer DFS/BFS da source no grafo residual
- Aresta (u,v) está no min-cut se u é alcançável e v não é alcançável
- Cuidado: conexões são bidirecionais, mas min-cut pode cortar em uma direção
- Listar todas as arestas que separam os dois componentes

ALGORITMO MIN-CUT RECONSTRUCTION:
1. Executar max-flow de source (1) para sink (2)
2. No grafo residual, fazer DFS/BFS da source
3. Marcar todos os vértices alcançáveis da source
4. Para cada aresta original (u,v):
   - Se u é alcançável e v não é alcançável: aresta está no cut
   - Adicionar (u,v) à lista de corte
5. Imprimir todas as arestas do corte

VERIFICAÇÃO:
- Após remover arestas do min-cut, deve ser impossível ir de 1 para 2
- Soma dos custos das arestas cortadas = valor do max-flow
- Qualquer subconjunto próprio das arestas não separa completamente

FORMATO DE SAÍDA:
- Cada linha: dois números representando cidades conectadas por aresta cortada
- Ordem não importa (qualquer ordem das arestas é válida)
- Linha em branco após cada caso
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    int n, m;
    while(cin >> n >> m && (n != 0 || m != 0)) {
        
        // 1. Ler especificação da rede:
        //    - n cidades, m conexões
        //    - Para cada conexão: cidade1, cidade2, custo
        
        // 2. Construir grafo com custos como capacidades
        //    - Conexões bidirecionais
        
        // 3. Executar max-flow de cidade 1 para cidade 2
        
        // 4. Identificar min-cut:
        //    - DFS/BFS no grafo residual a partir da source (1)
        //    - Marcar vértices alcançáveis
        //    - Arestas que conectam alcançável → não-alcançável estão no cut
        
        // 5. Imprimir arestas do min-cut
        
        // 6. Linha em branco após cada caso
        
    }
    
    return 0;
}