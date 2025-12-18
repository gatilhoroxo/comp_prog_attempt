/*
PROBLEMA A - ALLOCATION (ALOCAÇÃO DE APLICAÇÕES)

ANÁLISE DO PROBLEMA:
- 10 computadores (0-9) que podem executar aplicações
- Cada computador só executa uma aplicação por vez
- Aplicações A-Z podem ser executadas em computadores específicos
- Múltiplos usuários podem trazer a mesma aplicação (precisam computadores diferentes)
- Determinar se é possível alocar todas as aplicações solicitadas

ESTRATÉGIA DE SOLUÇÃO:
1. Problema de Maximum Bipartite Matching (emparelhamento bipartido máximo)
2. Lado esquerdo: instâncias de aplicações (expandir aplicação com N usuários em N instâncias)
3. Lado direito: computadores (0-9)
4. Aresta existe se aplicação pode executar no computador
5. Verificar se matching perfeito é possível (todas as aplicações são alocadas)

ALGORITMOS NECESSÁRIOS:
- Bipartite Matching (algoritmo húngaro ou Ford-Fulkerson)
- Alternativa: Maximum Flow (modelar como rede de fluxo)
- DFS para encontrar augmenting paths

PASSOS PARA IMPLEMENTAR:
1. Parse da entrada para extrair aplicações, quantidades e computadores válidos
2. Expandir cada aplicação em múltiplas instâncias (se vários usuários)
3. Construir grafo bipartido: instâncias → computadores
4. Executar algoritmo de matching
5. Se matching completo: reconstruir alocação e imprimir
6. Senão: imprimir "!"

ESTRUTURAS DE DADOS:
- Vector para armazenar quais computadores cada aplicação pode usar
- Vector para contar instâncias de cada aplicação
- Grafo bipartido ou matriz de adjacência
- Array de matching para resultado

COMPLEXIDADE:
- Tempo: O(V * E) onde V = instâncias + computadores, E = conexões possíveis
- Espaço: O(V + E)

DICAS:
- Use algoritmo de matching bipartido (Hungarian ou DFS iterativo)
- Para cada aplicação com N usuários, crie N instâncias separadas
- Reconstrua a saída percorrendo o matching encontrado
- Cuidado com parsing: formato "A4 01234;" significa aplicação A, 4 usuários, computadores 0,1,2,3,4

ALGORITMO DE MATCHING (DFS):
1. Para cada instância de aplicação não matchada:
   - Tentar encontrar augmenting path usando DFS
   - Se encontrar: atualizar matching
2. Se todas as instâncias foram matchadas: sucesso
3. Senão: impossível

PARSING:
- Linha formato: "APLICACAO + NUMERO_USUARIOS + ESPAÇO + COMPUTADORES + ;"
- Exemplo: "A4 01234;" = aplicação A, 4 usuários, computadores 0,1,2,3,4
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler entrada dia por dia até EOF
    
    // 2. Para cada dia:
    //    - Parse das job descriptions
    //    - Expandir aplicações em instâncias individuais
    //    - Construir grafo bipartido
    
    // 3. Executar algoritmo de bipartite matching
    
    // 4. Se matching completo:
    //    - Reconstruir alocação nos computadores 0-9
    //    - Imprimir string de 10 caracteres
    
    // 5. Senão: imprimir "!"
    
    return 0;
}