//UVa 11547 - Automatic Answer
//apenas ler o problema
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans = ((((((n*567)/9) + 7492)*235)/47 - 498) % 100)/10;
        cout << abs(ans) << '\n';
    }

    return 0;
}