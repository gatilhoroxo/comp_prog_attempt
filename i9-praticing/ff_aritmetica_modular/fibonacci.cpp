//UVa 10229 - Modular Fibonacci
//nao terminei
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fib(ll a){
    if(a == 0) return 0;
    if(a == 1) return 1;
    return fib(a-1) + fib(a-2);
}

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    while(cin >> n >> m){
        ll fibonacci = fib(n);
        cout << modular_exp(2,m,fibonacci);
    }

    return 0;
}