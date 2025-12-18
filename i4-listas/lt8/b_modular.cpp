//aritmetica modular
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll MOD = pow(10, 9) + 7;

ll mod_from_string(string& value){
    ll rem = 0;
    for(char c : value){
        rem = ((rem * 10) % MOD + (c - '0')) % MOD;
    }
    return rem;
}

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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    //int t; cin >> t; while(t--)
    
    {
        string x, op, y;
        cin >> x >> op >> y;

        ll ans = 0;
        
        ll px = mod_from_string(x);
        ll py = mod_from_string(y);
        switch(op[0]){
            case '+':
                ans = soma_mod(px, py);
                break;
            case '-':
                ans = sub_mod(px, py);
                break;
            case '*':
                ans = mult_mod(px, py);
                break;
            case '^': 
                ans = exp_mod(px, y);
                break;
            default:
                break;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}
