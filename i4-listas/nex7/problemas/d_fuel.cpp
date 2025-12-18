/*
PROBLEMA D - FUEL ECONOMY (ECONOMIA DE COMBUSTÍVEL)

ANÁLISE DO PROBLEMA:
- Carro precisa viajar de 0 a destino n
- Tanque capacidade c, consome 1 unidade por distância
- Postos de combustível em algumas posições
- Minimizar número de paradas ou determinar se é impossível

ESTRATÉGIA DE SOLUÇÃO:
1. Algoritmo Greedy: sempre ir o mais longe possível antes de reabastecer
2. Usar heap para gerenciar postos "disponíveis" (dentro do alcance)
3. Só reabastecer quando necessário (quando não conseguir chegar ao próximo posto)

ALGORITMOS NECESSÁRIOS:
- Greedy com Priority Queue
- Simulação de movimento

PASSOS PARA IMPLEMENTAR:
1. Ordenar estações por posição (já podem estar ordenadas)
2. Adicionar destino como "posto" com preço 0
3. Usar max heap para preços dos postos no alcance
4. Simular viagem: avançar até não poder mais, então reabastecer no posto mais barato disponível

ESTRUTURAS DE DADOS:
- Vector de pares (posição, preço)
- Priority queue (max heap) para preços
- Variáveis: posição atual, combustível atual, número de paradas

COMPLEXIDADE:
- Tempo: O(n log n) onde n é número de postos
- Espaço: O(n)

DICAS:
- Sempre reabasteça quando não conseguir chegar ao próximo posto necessário
- Use max heap para sempre escolher o posto mais barato no alcance
- Cuidado com o caso onde é impossível (distância entre postos > capacidade)
- Lembre-se que cada posto só pode ser usado uma vez

ALGORITMO DETALHADO:
1. Adicionar destino final como "posto"
2. Para cada posição objetivo (posto ou destino):
   - Adicionar postos no alcance atual ao heap
   - Enquanto combustível insuficiente para chegar:
     - Se heap vazio: retornar -1 (impossível)
     - Reabastecer no posto mais barato (topo do heap)
     - Incrementar contador de paradas
   - Mover para próxima posição (consumir combustível)

CASO ESPECIAL:
- Se distância inicial > capacidade: impossível desde o início
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // TODO: Implementar sua solução aqui
    
    // 1. Ler parâmetros: n, c
    
    // 2. Ler postos de combustível
    
    // 3. Adicionar destino final como "posto" com preço 0
    
    // 4. Simular viagem usando algoritmo greedy:
    //    - Manter heap de postos no alcance
    //    - Reabastecer apenas quando necessário
    //    - Escolher sempre o posto mais barato disponível
    
    // 5. Retornar número mínimo de paradas ou -1 se impossível
    
    return 0;
}