#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

/*
    TO DO: resolver isso aqui, está dando WA no caso 81 AAAAAAAAAAAAAAAAA
*/

ll knap(int x, vi& p, vi& val, int n){
    int maxp = x+5;
    vl Kn(maxp, LONG_LONG_MAX);
    Kn[0] = 0;
    for(int mot=0; mot<n; mot++){
        for(int pes=x+4; pes>=p[mot]; pes--){
            if(Kn[pes-p[mot]] != LONG_LONG_MAX){
                Kn[pes] = min(Kn[pes], val[mot] + Kn[pes-p[mot]]);
            } 
        }
    }
    ll ans = LONG_LONG_MAX;
    for(int i = x; i < maxp; i++)
        ans = min(ans, Kn[i]);
    if(Kn[x] == LONG_LONG_MAX) return -1;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >>t; while(t--)
    {
    
    /*pessoas e num de carros*/
    int x, n; cin >> x >> n;
    /*valor e peso, nessa ordem*/
    /*qtd de pessoas e valor por carro*/
    vi p(n),v(n);
    for(int i=0; i<n; i++){
        cin >> p[i] >> v[i]; 
    }

    ll ans = knap(x,p,v,n);

    cout << ans << '\n';
    
    
    }
}