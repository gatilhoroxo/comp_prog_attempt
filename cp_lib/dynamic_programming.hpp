#ifndef DYNAMIC_PROGRAMMING_HPP
#define DYNAMIC_PROGRAMMING_HPP

#include "cp_lib.hpp"

// ==================== 0/1 Knapsack ====================
// Uso: Problema da mochila 0/1 clássico O(nW)
class Knapsack {
public:
    // Versão que retorna apenas o valor máximo
    static int knapsack_01(int capacity, vi& weights, vi& values, int n) {
        vvi dp(n + 1, vi(capacity + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= capacity; w++) {
                if(weights[i-1] <= w) {
                    dp[i][w] = max(
                        values[i-1] + dp[i-1][w - weights[i-1]],
                        dp[i-1][w]
                    );
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        return dp[n][capacity];
    }

    // Versão alternativa (mesma funcionalidade)
    static int solve(int capacity, vi& weights, vi& values, int n) {
        vvi K(n + 1, vi(capacity + 1));
        
        for(int i = 0; i <= n; i++) {
            for(int w = 0; w <= capacity; w++) {
                if(i == 0 || w == 0) {
                    K[i][w] = 0;
                } else if(weights[i-1] <= w) {
                    K[i][w] = max(
                        values[i-1] + K[i-1][w - weights[i-1]], 
                        K[i-1][w]
                    );
                } else {
                    K[i][w] = K[i-1][w];
                }
            }
        }
        return K[n][capacity];
    }

    // Versão com reconstrução da solução
    static pair<int, vi> knapsack_with_items(int capacity, vi& weights, vi& values, int n) {
        vvi dp(n + 1, vi(capacity + 1, 0));
        
        // Preenche a tabela DP
        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= capacity; w++) {
                if(weights[i-1] <= w) {
                    dp[i][w] = max(
                        values[i-1] + dp[i-1][w - weights[i-1]],
                        dp[i-1][w]
                    );
                } else {
                    dp[i][w] = dp[i-1][w];
                }
            }
        }
        
        // Reconstrói a solução
        vi items;
        int w = capacity;
        for(int i = n; i > 0 && w > 0; i--) {
            if(dp[i][w] != dp[i-1][w]) {
                items.push_back(i - 1);  // Item i-1 foi incluído
                w -= weights[i-1];
            }
        }
        reverse(items.begin(), items.end());
        
        return {dp[n][capacity], items};
    }

    // Knapsack ilimitado (unbounded)
    static int unbounded_knapsack(int capacity, vi& weights, vi& values, int n) {
        vi dp(capacity + 1, 0);
        
        for(int w = 1; w <= capacity; w++) {
            for(int i = 0; i < n; i++) {
                if(weights[i] <= w) {
                    dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
                }
            }
        }
        return dp[capacity];
    }

    // Knapsack otimizado em espaço O(W)
    static int knapsack_space_optimized(int capacity, vi& weights, vi& values, int n) {
        vi prev(capacity + 1, 0), curr(capacity + 1, 0);
        
        for(int i = 1; i <= n; i++) {
            for(int w = 1; w <= capacity; w++) {
                if(weights[i-1] <= w) {
                    curr[w] = max(
                        values[i-1] + prev[w - weights[i-1]],
                        prev[w]
                    );
                } else {
                    curr[w] = prev[w];
                }
            }
            swap(prev, curr);
        }
        return prev[capacity];
    }
};

// ==================== Longest Common Subsequence ====================
class LCS {
public:
    // Retorna o tamanho da LCS
    static int lcs_length(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vvi dp(m + 1, vi(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    // Retorna a própria LCS
    static string lcs_string(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vvi dp(m + 1, vi(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        // Reconstrói a LCS
        string lcs = "";
        int i = m, j = n;
        while(i > 0 && j > 0) {
            if(s1[i-1] == s2[j-1]) {
                lcs = s1[i-1] + lcs;
                i--; j--;
            } else if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        return lcs;
    }
};


// ==================== Longest Increasing Subsequence ====================
class LIS {
public:
    // LIS O(n²)
    static int lis_dp(vi& arr) {
        int n = arr.size();
        vi dp(n, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    // LIS O(n log n) usando busca binária
    static int lis_binary_search(vi& arr) {
        vector<int> lis;
        
        for(int x : arr) {
            auto it = lower_bound(lis.begin(), lis.end(), x);
            if(it == lis.end()) {
                lis.push_back(x);
            } else {
                *it = x;
            }
        }
        return lis.size();
    }
};


// ==================== Edit Distance (Levenshtein) ====================
class EditDistance {
public:
    static int min_edit_distance(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        vvi dp(m + 1, vi(n + 1));
        
        // Inicialização
        for(int i = 0; i <= m; i++) dp[i][0] = i;
        for(int j = 0; j <= n; j++) dp[0][j] = j;
        
        // Preenche a tabela
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i-1][j],     // Deleção
                        dp[i][j-1],     // Inserção
                        dp[i-1][j-1]    // Substituição
                    });
                }
            }
        }
        return dp[m][n];
    }
};


// ==================== Coin Change ====================
class CoinChange {
public:
    // Número mínimo de moedas para fazer o valor
    static int min_coins(vi& coins, int amount) {
        vi dp(amount + 1, INF);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
            for(int coin : coins) {
                if(coin <= i && dp[i - coin] != INF) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == INF ? -1 : dp[amount];
    }

    // Número de maneiras de fazer o valor
    static int count_ways(vi& coins, int amount) {
        vi dp(amount + 1, 0);
        dp[0] = 1;
        
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};


// ==================== Matrix Chain Multiplication ====================
class MatrixChain {
public:
    // Retorna número mínimo de multiplicações
    static int min_multiplications(vi& dimensions) {
        int n = dimensions.size() - 1;  // Número de matrizes
        vvi dp(n, vi(n, 0));
        
        for(int len = 2; len <= n; len++) {
            for(int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;
                
                for(int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k+1][j] + 
                               dimensions[i] * dimensions[k+1] * dimensions[j+1];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[0][n-1];
    }
};

#endif // DYNAMIC_PROGRAMMING_HPP
