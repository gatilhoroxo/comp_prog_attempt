//UVa 11044 - Searching for Nessy
//busquei a resposta da formula
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        //eu pensei que era isso 
        //ans = ((n-2)/2)*((m-2)/2);
        int ans = (m/3)*(n/3);
        cout << ans << '\n';
    }

    return 0;
}