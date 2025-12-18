#include "../cp_lib.hpp"
//#include "bits/stdc++.h"
using namespace std;

// =============== TEORIA DOS NUMEROS ===================

// --------------- exponenciação modular rápida ---------------
int modular_exp(int base, int exp, int  mod){
    int resultado = 1;
    base = base % mod;

    while(exp>0){
        if(exp%2!=0){
            resultado = (resultado*base)%mod;
        }
        exp /= 2;
        base = (base*base)%mod;
    }
    return resultado;
}

// --------------- algoritmo de euclides ---------------

// .......... máximo divisor comum
int mdc(int a, int b){
    while(b!=0){
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

// ......... minimo multiplo comum
int mmc(int a, int b){
    return (a*b) / mdc(a,b);
}

// --------------- inverso modular ---------------

// ......... fermat
int inverso_modular(int a, int m){
    //se m é primo, então
    //teorema: a^(m-1) === 1 (mod m)
    //portanto: a^(m-2) === a^(-1) (mod m)
    return modular_exp(a,m-2,m);
}

//

ll MOD = pow(10,9) + 7;

ll fermat(string& exp_str){
    ll mod_fermat = 0;
    for(char c : exp_str){
        mod_fermat = (mod_fermat * 10 + (c - '0')) % (MOD - 1);
    }
    
    return mod_fermat;
}

ll exp_mod(ll& base, string& exp_str){
    if(base % MOD == 0) return 0;
    
    ll exp = fermat(exp_str);

    ll resultado = 1;
    base = base % MOD;

    while(exp>0){
        if(exp%2!=0){
            resultado = (resultado*base)%MOD;
        }
        exp /= 2;
        base = (base*base)%MOD;
    }
    return resultado;
}

ll soma_mod(ll& a, ll& b){
    return ((a%MOD) + (b%MOD))%MOD;
}

ll sub_mod(ll a, ll b){
    ll result = ((a%MOD) - (b%MOD)) % MOD;
    if(result < 0) result += MOD;
    return result;
}

ll mult_mod(ll a, ll b){
    return ((a%MOD) * (b%MOD))%MOD;
}
