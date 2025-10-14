//UVA 12455 - Bars
//nao terminei (falta o caso 2)
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, p; cin >> n >> p;
        vector<int> vt(p);
        for(auto &i: vt) cin >> i;
        sort(vt.begin(), vt.end(), greater<int>());
        for(auto &i: vt) cout << i << ' '; cout << '\n';
        int buff = n;
        for(auto i: vt) {
            buff-=i;
            if(buff<0) { buff+=i; break;}
            else if(buff==0) { break; }
        }
        if(buff == 0) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

    return (0);
}