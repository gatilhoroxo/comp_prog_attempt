//UVa 00501 - Black Box
//nao terminei
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int k; cin >> k;
    
    while(k--){
        int m, n;
        cin >> m >> n;
        vector<int> a(m);
        for(int i=0; i<m; i++){
            cin >> a[i];
        }
        vector<int> u(n);
        for(int i=0; i<n; i++){
            cin >> u[i];
        }
        int q = 0;
        set<int> order;
        for(auto v: a){
            order.insert(v);
            for(int i=q; i<u.size() && u[q] == order.size(); i++){
                auto o = order.find(q+1);
                cout << (*o) << '\n';
                q++;
            }
        }

        // for(auto o: order){ cout << o << ' '; }  cout << '\n';
        // for(auto i: u){ cout << i << ' '; } cout << '\n';

    }


    return 0;
}