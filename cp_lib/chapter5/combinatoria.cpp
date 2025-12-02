#include "../cp_lib.hpp"
#include "aritmetica_modular.cpp"
//#include "bits/stdc++.h"
using namespace std;

// ======================= COMBINATORIA ======================= 

// --------------- coeficiente binomial (DP) ---------------
int coef_binomial(int n, int k){
    if(k>n){ return 0; }
    if(k==0 || k==n) return 1;

    k = min(k, n-k);

    //nao entendi
    vi coef(k,0);
    coef[0] = 1;

    for(int i=1; i<=n; i++){
        for(int j=min(i,k); j>=1; j--){
            coef[j] = coef[j]+coef[j-1];
        }
    }

    return coef[k];
}

// --------------- coeficiente binomial (modular) ---------------
int coef_binomial_modular(int n, int k, int mod){
    if(k>n) return 0;
    
    vi fat(n+1);
    fat[0]=1;
    for(int i=1;i<=n;i++){
        fat[i]=(fat[i-1]*i)%mod;
    }
    
    int numerador = fat[n];
    int denominador = (fat[k]*fat[n-k] % mod);
    
    int inv_den = inverso_modular(denominador, mod);

    return (numerador *inv_den) % mod;
}

// --------------- inclusao exclusao ----------------
int inclusao_exclusao(vi conjuntos){
    int n = conjuntos.size();
    if(n == 0) return 0;

    int resultado = 0;
    unsigned limit = 1u << n; // todos os subconjuntos não vazios serão representados por mask = 1..limit-1

    for(unsigned mask = 1u; mask < limit; ++mask){
        // interseção inicial com todos os bits por 1
        unsigned inter = ~0u;
        for(int i = 0; i < n; ++i){
            if(mask & (1u << i)){
                inter &= static_cast<unsigned>(conjuntos[i]);
            }
        }

        int inter_size = __builtin_popcount(inter);      // número de elementos na interseção
        int bits_ativos = __builtin_popcount(mask);      // quantos conjuntos foram selecionados

        if(bits_ativos % 2 == 1) resultado += inter_size;
        else resultado -= inter_size;
    }

    return resultado;
}

#include <type_traits>
// para containers como vector<uint64_t>, vector<unsigned>
template<typename MaskContainer>
int inclusao_exclusao(const MaskContainer& conjuntos){
    using Mask = typename MaskContainer::value_type;
    static_assert(std::is_integral<Mask>::value, "Mask must be integral");

    size_t n = conjuntos.size();
    if(n == 0) return 0;

    int resultado = 0;
    unsigned limit = 1u << n;

    for(unsigned mask = 1u; mask < limit; ++mask){
        Mask inter = ~static_cast<Mask>(0);
        for(size_t i = 0; i < n; ++i){
            if(mask & (1u << i)){
                inter &= conjuntos[i];
            }
        }

        int inter_size = __builtin_popcountll(static_cast<unsigned long long>(inter));
        int bits_ativos = __builtin_popcount(mask);

        resultado += (bits_ativos & 1) ? inter_size : -inter_size;
    }

    return resultado;
}