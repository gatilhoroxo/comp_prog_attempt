/*
PROBLEMA F - COMMANDO MISSION (MISSÃO COMANDO)

ANÁLISE DO PROBLEMA:
- Soldados devem capturar objetivos específicos
- Cada soldado tem conjunto de objetivos que pode capturar
- Minimizar número total de soldados usados
- Clássico problema de Set Cover

ESTRATÉGIA DE SOLUÇÃO:
1. Problema NP-hard: Set Cover
2. Usar algoritmo greedy (aproximação): sempre escolher soldado que cobre mais objetivos não cobertos
3. Alternativa: força bruta se números pequenos (bitmask DP)
4. Heurística greedy é boa aproximação

ALGORITMOS NECESSÁRIOS:
- Greedy Set Cover
- Alternativa: Bitmask DP para solução exata

PASSOS PARA IMPLEMENTAR (Greedy):
1. Manter conjunto de objetivos ainda não capturados
2. Enquanto há objetivos não capturados:
   - Escolher soldado que captura mais objetivos não capturados
   - Marcar esses objetivos como capturados
   - Incrementar contador de soldados
3. Retornar contador

ESTRUTURAS DE DADOS:
- Set ou bitset para objetivos não capturados
- Vector de sets para cada soldado (objetivos que pode capturar)

COMPLEXIDADE:
- Greedy: O(nm) onde n = soldados, m = objetivos
- Bitmask DP: O(n * 2^m) - só viável para m pequeno

DICAS:
- Greedy não garante solução ótima, mas é boa aproximação
- Para solução exata em casos pequenos: usar bitmask DP
- Em cada iteração greedy, recalcular qual soldado cobre mais objetivos restantes
- Se nenhum soldado pode capturar objetivos restantes: problema impossível

ALGORITMO GREEDY DETALHADO:
1. objetivos_restantes = {1, 2, ..., m}
2. soldados_usados = 0
3. Enquanto objetivos_restantes não vazio:
   - melhor_soldado = -1, max_cobertura = 0
   - Para cada soldado i:
     - cobertura = |soldado[i] ∩ objetivos_restantes|
     - Se cobertura > max_cobertura:
       - max_cobertura = cobertura, melhor_soldado = i
   - Se max_cobertura == 0: retornar impossível
   - objetivos_restantes -= soldado[melhor_soldado]
   - soldados_usados++

ALTERNATIVA BITMASK DP (se m ≤ 20):
- dp[mask] = menor número de soldados para cobrir objetivos em mask
- Para cada soldado, tentar adicionar aos estados existentes
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler parâmetros: n (soldados), m (objetivos)
    
    // 2. Para cada soldado, ler objetivos que pode capturar
    
    // 3. Implementar algoritmo greedy Set Cover:
    //    - Enquanto há objetivos não cobertos
    //    - Escolher soldado que cobre mais objetivos restantes
    //    - Atualizar objetivos cobertos
    
    // 4. Retornar número mínimo de soldados
    
    // Alternativa para casos pequenos (m ≤ 20):
    // Usar bitmask DP para solução exata
    
    return 0;
}