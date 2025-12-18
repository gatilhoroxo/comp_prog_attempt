//UVa 11498 - Division of Nlogonia
//demorei um pouco para entender o input
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int k; cin>>k;
        if(k==0) break;
        int n, m; cin >> n >> m;
        while(k--){
            int x, y; cin>>x>>y;
            string ans = "";
            if(y==m || x==n) { ans = "divisa"; }
            else { 
                if(y<m) { ans += "S"; }
                else { ans += "N"; }
                if(x<n) {ans += "O";}
                else { ans += "E"; }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}