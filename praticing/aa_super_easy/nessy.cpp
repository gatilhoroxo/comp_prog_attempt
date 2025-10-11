//UVa 11044 - Searching for Nessy
//wrong answer (vejo isso depois)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int ab = min(n,m);
        int col = ((m-2)/2);
        int lin = ((n-2)/2);
        int square = (ab-2)/2;
        if(n == m) cout << (col*lin) << '\n';
        else cout << (col*lin - square) << '\n';
    }

    return 0;
}