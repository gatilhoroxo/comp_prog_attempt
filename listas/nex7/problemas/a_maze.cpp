/*
PROBLEMA A - MAZE (LABIRINTO)

ANÁLISE DO PROBLEMA:
- Grid 6x6 com paredes
- Encontrar caminho mais curto entre start e end
- 3 paredes que podem ser horizontais ou verticais
- Movimentos: N, S, E, W (Norte, Sul, Leste, Oeste)

ESTRATÉGIA DE SOLUÇÃO:
1. Representar o grid e as paredes
2. Usar BFS para encontrar o caminho mais curto
3. Rastrear o caminho para reconstruir as direções

ALGORITMOS NECESSÁRIOS:
- BFS (Breadth-First Search)
- Representação de grid com paredes
- Reconstrução de caminho

PASSOS PARA IMPLEMENTAR:
1. Ler coordenadas de start e end
2. Ler as 3 paredes e marcar no grid
3. Implementar BFS salvando o predecessor de cada célula
4. Reconstruir o caminho do end até start
5. Converter o caminho em direções (N, S, E, W)

ESTRUTURAS DE DADOS:
- Matriz para representar o grid
- Queue para BFS
- Matriz de visitados
- Matriz de predecessores ou mapa de direções

COMPLEXIDADE:
- Tempo: O(36) = O(1) para grid 6x6
- Espaço: O(36) = O(1)

DICAS:
- Cuidado com a indexação (pode ser 1-based ou 0-based)
- As paredes bloqueiam movimento entre células adjacentes
- BFS garante o menor número de movimentos
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler coordenadas de start e end
    
    // 2. Ler as paredes e processar
    
    // 3. Implementar BFS com reconstrução de caminho
    
    // 4. Imprimir a sequência de movimentos
    
    return 0;
}