//creating strings ii
#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000'007
using ll = long long;

ll mult_mod(ll a,ll  b){
    return (((a%MOD) * (b%MOD))%MOD);
}

ll pow_mod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll div_mod(ll a, ll b){
    ll inv = pow_mod(b, MOD - 2, MOD);
    return mult_mod(a, inv);
}

int fat(int n){
    if(n<=0) return 0;
    if(n==1) return 1;
    return mult_mod(n,fat(n-1));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    string s; 
    cin >> s;
    
    //qual a quantidade total de letras na string
    ll sz = s.size();
    
    //qual a quantidade de letras diferentes na string
    map<char,ll> mp;
    for(auto&c:s){
        mp[c]=mp[c]+1;
    }

    //quantas combinações de strings diferentes podem ser formadas
    int tam = fat(sz);
    int cal=1;
    for(auto&m:mp){
        int temp = fat(m.second);
        cal = mult_mod(cal, temp);
    }
    tam = div_mod(tam, cal);

    cout << tam % MOD << '\n';

    }

    return 0;
}