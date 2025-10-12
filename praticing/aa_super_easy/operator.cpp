//UVa 11172 - Relational Operators
//de primeira
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        if(a > b) cout << '>';
        else if(a < b) cout << '<';
        else cout << '=';
        cout << '\n';
    }

    return 0;
}