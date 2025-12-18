//planets
#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n, cost; 
    cin >> n >> cost;
    map<int,int> planets;
    for(int i=0; i<n; i++){
        int entrada; cin >> entrada;
        planets[entrada]+=1;
    }

    ll ans=0;
    for(auto&[p,s]:planets){
        if(s > cost){
            ans+=cost;
        } else {
            ans += s;
        }
    }

    cout << ans << '\n';


    }

    return 0;
}