# Resumo - Capítulo 5: Matemática em Programação Competitiva

## 📚 Visão Geral

Este capítulo aborda conceitos matemáticos fundamentais frequentemente utilizados em programação competitiva, incluindo teoria dos números, combinatória, probabilidade e teoria dos jogos.

---

## 1️⃣ ARITMÉTICA MODULAR E TEORIA DOS NÚMEROS

### 🔹 Conceitos Principais
- **Operações modulares**: (a + b) % m, (a * b) % m, (a - b + m) % m
- **Exponenciação modular rápida**: calcular (a^b) % m eficientemente
- **Inverso modular**: encontrar x tal que (a * x) % m = 1
- **MDC e MMC**: Máximo Divisor Comum e Mínimo Múltiplo Comum
- **Números primos**: testes de primalidade, Crivo de Eratóstenes

### 💻 Pseudocódigo: Exponenciação Modular Rápida (Fast Exponentiation)

```
função modular_exp(base, exp, mod):
    resultado = 1
    base = base % mod
    
    enquanto exp > 0:
        se exp é ímpar:
            resultado = (resultado * base) % mod
        
        exp = exp / 2  // divisão inteira
        base = (base * base) % mod
    
    retornar resultado
```

**Complexidade**: O(log n)

### 💻 Pseudocódigo: MDC (Algoritmo de Euclides)

```
função mdc(a, b):
    enquanto b ≠ 0:
        temp = b
        b = a % b
        a = temp
    
    retornar a

função mmc(a, b):
    retornar (a * b) / mdc(a, b)
```

**Complexidade**: O(log(min(a, b)))

### 💻 Pseudocódigo: Crivo de Eratóstenes

```
função crivo_eratostenes(n):
    eh_primo[0..n] = [verdadeiro] * (n + 1)
    eh_primo[0] = eh_primo[1] = falso
    
    para p de 2 até raiz_quadrada(n):
        se eh_primo[p]:
            para i de p*p até n com passo p:
                eh_primo[i] = falso
    
    primos = []
    para i de 2 até n:
        se eh_primo[i]:
            primos.adicionar(i)
    
    retornar primos
```

**Complexidade**: O(n log log n)

### 💻 Pseudocódigo: Inverso Modular (usando Fermat)

```
função inverso_modular(a, m):
    // Assume que m é primo
    // Pelo Pequeno Teorema de Fermat: a^(m-1) ≡ 1 (mod m)
    // Portanto: a^(m-2) ≡ a^(-1) (mod m)
    retornar modular_exp(a, m - 2, m)
```

### 🎯 Problemas Sugeridos - Aritmética Modular

1. **UVa 10229** - Modular Fibonacci
2. **UVa 10469** - To Carry or not to Carry
3. **UVa 10127** - Ones
4. **Codeforces 630I** - Parking Lot
5. **SPOJ LASTDIG** - The Last Digit

---

## 2️⃣ FATORAÇÃO E DIVISORES

### 🔹 Conceitos Principais
- Fatoração em números primos
- Contagem de divisores
- Soma de divisores
- Função Totiente de Euler φ(n)

### 💻 Pseudocódigo: Fatoração em Primos

```
função fatoracao_prima(n):
    fatores = []
    
    // Verificar divisibilidade por 2
    enquanto n % 2 == 0:
        fatores.adicionar(2)
        n = n / 2
    
    // Verificar números ímpares até √n
    para i de 3 até raiz_quadrada(n) com passo 2:
        enquanto n % i == 0:
            fatores.adicionar(i)
            n = n / i
    
    // Se n > 2, então é primo
    se n > 2:
        fatores.adicionar(n)
    
    retornar fatores
```

**Complexidade**: O(√n)

### 💻 Pseudocódigo: Contar Divisores

```
função contar_divisores(n):
    fatores_primos = fatoracao_prima(n)
    frequencias = contar_frequencias(fatores_primos)
    
    total_divisores = 1
    para cada (primo, exp) em frequencias:
        total_divisores *= (exp + 1)
    
    retornar total_divisores
```

### 💻 Pseudocódigo: Função Totiente de Euler

```
função totiente_euler(n):
    resultado = n
    
    // Considerar todos os fatores primos de n
    para p de 2 até raiz_quadrada(n):
        se n % p == 0:
            // Remover todas as ocorrências de p
            enquanto n % p == 0:
                n = n / p
            // Aplicar fórmula: φ(n) *= (1 - 1/p)
            resultado -= resultado / p
    
    se n > 1:
        resultado -= resultado / n
    
    retornar resultado
```

**Complexidade**: O(√n)

### 🎯 Problemas Sugeridos - Fatoração e Divisores

1. **UVa 10139** - Factovisors
2. **UVa 583** - Prime Factors
3. **UVa 10407** - Simple division
4. **SPOJ ETF** - Euler Totient Function
5. **UVa 11353** - A Different Kind of Sorting

---

## 3️⃣ COMBINATÓRIA

### 🔹 Conceitos Principais
- Coeficientes binomiais C(n, k)
- Triângulo de Pascal
- Permutações e Combinações
- Princípio da Inclusão-Exclusão

### 💻 Pseudocódigo: Coeficiente Binomial (Programação Dinâmica)

```
função coef_binomial(n, k):
    se k > n:
        retornar 0
    se k == 0 ou k == n:
        retornar 1
    
    // Otimização: C(n, k) = C(n, n-k)
    k = min(k, n - k)
    
    C[0..k] = [0] * (k + 1)
    C[0] = 1
    
    para i de 1 até n:
        para j de min(i, k) até 1 com passo -1:
            C[j] = C[j] + C[j-1]
    
    retornar C[k]
```

**Complexidade**: O(n * k)

### 💻 Pseudocódigo: Coeficiente Binomial (Modular)

```
função coef_binomial_modular(n, k, mod):
    se k > n:
        retornar 0
    
    // Pré-calcular fatoriais
    fat[0] = 1
    para i de 1 até n:
        fat[i] = (fat[i-1] * i) % mod
    
    // C(n, k) = n! / (k! * (n-k)!)
    numerador = fat[n]
    denominador = (fat[k] * fat[n - k]) % mod
    
    // Inverso modular do denominador
    inv_den = inverso_modular(denominador, mod)
    
    retornar (numerador * inv_den) % mod
```

### 💻 Pseudocódigo: Princípio da Inclusão-Exclusão

```
função inclusao_exclusao(conjuntos):
    n = tamanho(conjuntos)
    resultado = 0
    
    // Iterar por todos os subconjuntos não vazios
    para mascara de 1 até (2^n - 1):
        intersecao = calcular_intersecao(conjuntos, mascara)
        bits_ativos = contar_bits(mascara)
        
        se bits_ativos é ímpar:
            resultado += tamanho(intersecao)
        senão:
            resultado -= tamanho(intersecao)
    
    retornar resultado
```

### 🎯 Problemas Sugeridos - Combinatória

1. **UVa 10943** - How do you add?
2. **UVa 10910** - Marks Distribution
3. **UVa 11401** - Triangle Counting
4. **Codeforces 478D** - Red-Green Towers
5. **UVa 00369** - Combinations

---

## 4️⃣ PROBABILIDADE E VALOR ESPERADO

### 🔹 Conceitos Principais
- Probabilidade básica
- Probabilidade condicional
- Valor esperado (Expected Value)
- Programação dinâmica probabilística

### 💻 Pseudocódigo: Valor Esperado com DP

```
função valor_esperado_dp(estados):
    // ev[i] = valor esperado começando do estado i
    ev = array de tamanho n, inicializado com 0
    
    // Processar estados em ordem reversa
    para i de n-1 até 0 com passo -1:
        se estado[i] é terminal:
            ev[i] = recompensa[i]
        senão:
            ev[i] = 0
            para cada transicao possível do estado i:
                proximo_estado = transicao.destino
                probabilidade = transicao.prob
                custo = transicao.custo
                
                ev[i] += probabilidade * (custo + ev[proximo_estado])
    
    retornar ev[0]  // valor esperado do estado inicial
```

### 🎯 Problemas Sugeridos - Probabilidade

1. **UVa 10328** - Coin Toss
2. **UVa 10759** - Dice Throwing
3. **UVa 11762** - Race to 1
4. **Codeforces 148D** - Bag of mice
5. **UVa 10529** - Dumb Bones

---

## 5️⃣ TEORIA DOS JOGOS

### 🔹 Conceitos Principais
- Jogo de Nim
- Números de Grundy (Sprague-Grundy)
- Estados vencedores e perdedores
- Minimax

### 💻 Pseudocódigo: Jogo de Nim

```
função jogo_nim(pilhas):
    xor_sum = 0
    
    para cada pilha em pilhas:
        xor_sum ^= pilha  // XOR acumulativo
    
    se xor_sum == 0:
        retornar "Segundo jogador vence"
    senão:
        retornar "Primeiro jogador vence"
```

**Teorema de Sprague-Grundy**: O XOR de todos os valores de Grundy determina o vencedor.

### 💻 Pseudocódigo: Número de Grundy

```
função grundy(estado, memo):
    se estado em memo:
        retornar memo[estado]
    
    se estado é terminal:
        retornar 0
    
    // Calcular todos os estados alcançáveis
    alcancaveis = conjunto vazio
    
    para cada movimento possível:
        proximo = aplicar_movimento(estado, movimento)
        alcancaveis.adicionar(grundy(proximo, memo))
    
    // MEX (Minimum Excludant): menor número não negativo não presente
    mex = 0
    enquanto mex está em alcancaveis:
        mex += 1
    
    memo[estado] = mex
    retornar mex
```

### 💻 Pseudocódigo: Determinar Estado Vencedor/Perdedor

```
função eh_vencedor(estado, memo):
    se estado em memo:
        retornar memo[estado]
    
    se estado é terminal:
        memo[estado] = falso  // estado perdedor
        retornar falso
    
    // Se existe pelo menos um movimento para estado perdedor,
    // então este é um estado vencedor
    para cada movimento possível:
        proximo = aplicar_movimento(estado, movimento)
        se não eh_vencedor(proximo, memo):
            memo[estado] = verdadeiro
            retornar verdadeiro
    
    // Todos os movimentos levam a estados vencedores
    memo[estado] = falso
    retornar falso
```

### 🎯 Problemas Sugeridos - Teoria dos Jogos

1. **UVa 10165** - Stone Game
2. **UVa 10404** - Bachet's Game
3. **UVa 847** - A Multiplication Game
4. **SPOJ MCOINS** - Coins Game
5. **UVa 11311** - Exclusively Edible

---

## 6️⃣ SEQUÊNCIAS E RECORRÊNCIAS

### 🔹 Conceitos Principais
- Sequência de Fibonacci
- Números de Catalan
- Recorrências lineares
- Matriz de exponenciação para recorrências

### 💻 Pseudocódigo: Fibonacci com Exponenciação de Matriz

```
função multiplicar_matrizes(A, B, mod):
    C = matriz 2x2 inicializada com zeros
    
    para i de 0 até 1:
        para j de 0 até 1:
            para k de 0 até 1:
                C[i][j] += (A[i][k] * B[k][j]) % mod
                C[i][j] %= mod
    
    retornar C

função exp_matriz(M, n, mod):
    se n == 1:
        retornar M
    
    se n é par:
        metade = exp_matriz(M, n/2, mod)
        retornar multiplicar_matrizes(metade, metade, mod)
    senão:
        retornar multiplicar_matrizes(M, exp_matriz(M, n-1, mod), mod)

função fibonacci(n, mod):
    se n <= 1:
        retornar n
    
    // Matriz de transição para Fibonacci
    M = [[1, 1],
         [1, 0]]
    
    resultado = exp_matriz(M, n, mod)
    retornar resultado[0][1]
```

**Complexidade**: O(log n)

### 💻 Pseudocódigo: Números de Catalan

```
função catalan(n):
    se n <= 1:
        retornar 1
    
    // C(n) = (2n)! / ((n+1)! * n!)
    // ou C(n) = C(n, 2n) / (n+1)
    
    cat = [0] * (n + 1)
    cat[0] = cat[1] = 1
    
    para i de 2 até n:
        cat[i] = 0
        para j de 0 até i-1:
            cat[i] += cat[j] * cat[i-1-j]
    
    retornar cat[n]
```

### 🎯 Problemas Sugeridos - Sequências

1. **UVa 10229** - Modular Fibonacci
2. **UVa 10655** - Contemplation! Algebra
3. **SPOJ FIBOSUM** - Fibonacci Sum
4. **UVa 10689** - Yet another Number Sequence
5. **UVa 00991** - Safe Salutations

---

## 7️⃣ GEOMETRIA DOS NÚMEROS

### 🔹 Conceitos Principais
- Algoritmo de Euclides Estendido
- Equação Diofantina Linear
- Teorema Chinês do Resto

### 💻 Pseudocódigo: Algoritmo de Euclides Estendido

```
função euclides_estendido(a, b):
    se b == 0:
        retornar (a, 1, 0)  // mdc, x, y tal que ax + by = mdc
    
    (mdc, x1, y1) = euclides_estendido(b, a % b)
    
    x = y1
    y = x1 - (a / b) * y1
    
    retornar (mdc, x, y)
```

### 💻 Pseudocódigo: Equação Diofantina (ax + by = c)

```
função diofantina(a, b, c):
    (mdc, x0, y0) = euclides_estendido(a, b)
    
    se c % mdc != 0:
        retornar "Sem solução"
    
    // Solução particular
    x = x0 * (c / mdc)
    y = y0 * (c / mdc)
    
    // Solução geral:
    // x = x + k * (b / mdc)
    // y = y - k * (a / mdc)
    // para qualquer inteiro k
    
    retornar (x, y)
```

### 💻 Pseudocódigo: Teorema Chinês do Resto

```
função teorema_chines_resto(num, rem):
    // num[i] e rem[i] representam x ≡ rem[i] (mod num[i])
    n = tamanho(num)
    
    // Calcular o produto de todos os módulos
    produto = 1
    para i de 0 até n-1:
        produto *= num[i]
    
    resultado = 0
    para i de 0 até n-1:
        pp = produto / num[i]
        (_, inv, _) = euclides_estendido(pp, num[i])
        resultado += rem[i] * inv * pp
    
    retornar resultado % produto
```

### 🎯 Problemas Sugeridos - Geometria dos Números

1. **UVa 10104** - Euclid Problem
2. **UVa 10090** - Marbles
3. **UVa 10673** - Play with Floor and Ceil
4. **SPOJ CEQU** - Crucial Equation
5. **UVa 10916** - Factstone Benchmark

---

## 8️⃣ CICLOS E DETECÇÃO DE PADRÕES

### 🔹 Conceitos Principais
- Algoritmo de Floyd (Ciclo em Sequência)
- Detecção de período
- Birthday Paradox

### 💻 Pseudocódigo: Algoritmo de Floyd (Tartaruga e Lebre)

```
função detectar_ciclo_floyd(funcao, x0):
    // Encontrar um ponto no ciclo
    tartaruga = funcao(x0)
    lebre = funcao(funcao(x0))
    
    enquanto tartaruga != lebre:
        tartaruga = funcao(tartaruga)
        lebre = funcao(funcao(lebre))
    
    // Encontrar o início do ciclo
    mu = 0  // início do ciclo
    tartaruga = x0
    enquanto tartaruga != lebre:
        tartaruga = funcao(tartaruga)
        lebre = funcao(lebre)
        mu += 1
    
    // Encontrar o tamanho do ciclo
    lambda = 1  // tamanho do ciclo
    lebre = funcao(tartaruga)
    enquanto tartaruga != lebre:
        lebre = funcao(lebre)
        lambda += 1
    
    retornar (mu, lambda)
```

### 🎯 Problemas Sugeridos - Ciclos

1. **UVa 350** - Pseudo-Random Numbers
2. **UVa 10182** - Bee Maja
3. **UVa 11634** - Generate Random Numbers
4. **SPOJ ABSYS** - Anti-Blot System
5. **UVa 10245** - The Closest Pair Problem

---

## 📝 DICAS GERAIS DE IMPLEMENTAÇÃO

### ✅ Boas Práticas

1. **Use tipos de dados adequados**:
   - `long long` para evitar overflow (C++)
   - Considere BigInteger para números muito grandes (Java/Python)

2. **Operações modulares**:
   - Sempre aplique o módulo após cada operação
   - Para subtração: `(a - b + MOD) % MOD`
   - Para multiplicação: `((a % MOD) * (b % MOD)) % MOD`

3. **Pré-computação**:
   - Calcule fatoriais, primos, coeficientes binomiais antecipadamente quando possível
   - Use memoização para evitar cálculos repetidos

4. **Cuidado com precisão**:
   - Use `double` com cuidado em comparações
   - Considere trabalhar com frações quando possível
   - Define epsilon para comparações de ponto flutuante

### ⚠️ Armadilhas Comuns

1. **Overflow**: sempre verifique os limites dos tipos de dados
2. **Divisão por zero**: verifique denominadores antes de dividir
3. **Módulo negativo**: em algumas linguagens, módulo de números negativos pode dar resultado negativo
4. **TLE (Time Limit Exceeded)**: otimize algoritmos O(n²) para O(n log n) quando n > 10⁵

---

## 🎓 RECURSOS ADICIONAIS

### Livros Recomendados
- "Competitive Programming 3" - Steven & Felix Halim
- "Introduction to Algorithms" - CLRS
- "Concrete Mathematics" - Graham, Knuth, Patashnik

### Plataformas para Praticar
- **UVa Online Judge**: uva.onlinejudge.org
- **Codeforces**: codeforces.com
- **SPOJ**: spoj.com
- **AtCoder**: atcoder.jp
- **Project Euler**: projecteuler.net (foco matemático)

### Sites Úteis
- **CP-Algorithms**: cp-algorithms.com
- **OEIS**: oeis.org (Encyclopedia of Integer Sequences)
- **Wolfram MathWorld**: mathworld.wolfram.com

---

## 📊 COMPLEXIDADE DOS ALGORITMOS

| Algoritmo | Complexidade | Uso |
|-----------|-------------|-----|
| MDC (Euclides) | O(log n) | Encontrar máximo divisor comum |
| Exponenciação Modular | O(log n) | Calcular a^b mod m |
| Crivo de Eratóstenes | O(n log log n) | Encontrar todos os primos até n |
| Fatoração | O(√n) | Decompor em fatores primos |
| Fibonacci Matriz | O(log n) | n-ésimo termo de Fibonacci |
| Coef. Binomial DP | O(n * k) | Calcular C(n, k) |
| Grundy/Nim | O(estados * transições) | Teoria dos jogos |

---

## ✨ CONCLUSÃO

A matemática em programação competitiva é fundamental para resolver uma grande variedade de problemas. Pratique implementando cada algoritmo do zero, entendendo suas propriedades e aplicações. Comece com problemas mais simples e vá aumentando a dificuldade gradualmente.

**Boa sorte nos seus estudos! 🚀**
