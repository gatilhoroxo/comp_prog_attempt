//ok

#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n; //shops
    vector<int> x(n); //preços
    for(int i=0; i<n; i++){
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    int q; cin >> q; //dias planejados para compras
    for(int i=0; i<q; i++){
        int m; //dinheiro por dia
        cin >> m;

        
        //----------
        //binary search
        if(m >= x[n-1]){
            cout << n << '\n';
        }
        else if(m < x[0]) {
            cout << 0 << '\n';
        }
        else{
            auto it = upper_bound(x.begin(), x.end(), m);
            int pos = it - x.begin();
            cout <<  pos << "\n";
        }
    }



    return 0;
}