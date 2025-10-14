//UVA 12455 - Bars
//ok
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
        //sort(vt.begin(), vt.end(), greater<int>());
        //for(auto &i: vt) cout << i << ' '; cout << '\n';
        int buff = n;
        bool ok = false;

        for(int wt=0; wt< (1 << p) && !ok; wt++){
            buff=0;
            for(int j=0; j<p; j++){
                if(wt & (1 << j)){
                    buff+=vt[j];
                    if(buff>n) break;
                }
            }
            if(buff == n) ok = true;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return (0);
}