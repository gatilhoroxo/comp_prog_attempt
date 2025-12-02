#include "../cp_lib.hpp"
//#include "bits/stdc++.h"
using namespace std;

// ======================= fatoração e divisores ======================= 

// --------------- fatoração em primos ---------------
map<int,ii> fatoracao_prima(int n){
    map<int,ii> frequencias;
    int temp = n;

    if(temp <= 1) return frequencias;
    frequencias[2].first = 2;
    while(temp % 2 == 0){
        frequencias[2].second++;
        temp = temp / 2;
    }

    for(int i = 3; i * i <= temp; i += 2){
        while(temp % i == 0){
            frequencias[i].first = i;
            frequencias[i].second++;
            temp = temp/i;
        }
    }

    if(temp > 1){
        frequencias[temp]={temp,1};
    }

    return frequencias;
}

// --------------- contar divisores ---------------
int contar_divisores(int n){
    if(n <= 0) return 0;
    map<int,ii> frequencias = fatoracao_prima(n);

    int totaldivisores = 1;
    for(auto &par : frequencias){
        totaldivisores *= (par.second.second + 1);
    }
    return totaldivisores;
}

// ---------------- função totiente de euler
int totiente_euler(int n){
    int resultado = n;
    
    for(int p = 2; p<sqrt(n); p++){
        if(n%p==2){
            while(n%p==0){
                n /= p;
            }
            resultado -= resultado /p;
        }
    }
    if(n>1){
        resultado -= resultado/n;
    }

    return resultado;
}

// ---------------- calculando os numeros primos até determinado valor
vec(bool) crivo(){
    vec(bool) primos(MAX, true);
    primos[0] = primos[1] = false;
    for(int i=2; i<MAX;i++){
        if(primos[i] && (long long)i*i <= MAX) {
            for(int j=i+i; j<MAX; j+=i){
                primos[j] = false;
            }
        }
    }
    return primos;
}


