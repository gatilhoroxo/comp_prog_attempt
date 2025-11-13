/*
PROBLEMA B - SLIDING PUZZLE 3x3

ANÁLISE DO PROBLEMA:
- Puzzle 3x3 com números 1-9
- Dois tipos de movimento: horizontal (H) e vertical (V)
- Movimento horizontal: desloca linha inteira para direita (circular)
- Movimento vertical: desloca coluna inteira para cima (circular)
- Objetivo: chegar na configuração 1-9 ordenada

ESTRATÉGIA DE SOLUÇÃO:
1. Usar BFS para encontrar sequência mínima de movimentos
2. Representar estado como string ou array
3. Gerar todos os possíveis próximos estados
4. Verificar se configuração é atingível

ALGORITMOS NECESSÁRIOS:
- BFS (Breadth-First Search)
- Hashing de estados
- Simulação de movimentos

PASSOS PARA IMPLEMENTAR:
1. Ler configuração inicial
2. Representar estado de forma eficiente
3. Implementar movimentos H1, H2, H3, V1, V2, V3
4. BFS até encontrar estado objetivo
5. Reconstruir sequência de movimentos

ESTRUTURAS DE DADOS:
- String ou array para representar estado
- Queue para BFS
- Map/Set para estados visitados
- Estrutura para rastrear movimentos

COMPLEXIDADE:
- Estados possíveis: 9! = 362,880
- Tempo: O(9!) no pior caso
- Espaço: O(9!)

DICAS:
- Nem todas as configurações são solucionáveis
- Use string como chave para map de estados
- Cuidado com movimentos circulares
- BFS garante menor número de movimentos

MOVIMENTOS:
- H1: linha 1 → direita (circular)
- H2: linha 2 → direita (circular)  
- H3: linha 3 → direita (circular)
- V1: coluna 1 → cima (circular)
- V2: coluna 2 → cima (circular)
- V3: coluna 3 → cima (circular)
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Definir estado objetivo "123456789"
    
    // 2. Ler configuração inicial até encontrar "0"
    
    // 3. Implementar funções de movimento (H1, H2, H3, V1, V2, V3)
    
    // 4. BFS para encontrar caminho mínimo
    
    // 5. Verificar se é possível resolver ou imprimir "Not solvable"
    
    return 0;
}