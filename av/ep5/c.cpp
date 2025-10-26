//knapsack
//consegui tambem caraaaaaaa antes de dar 2h
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

ll knap(int w, vi wt, vi& val, int n){
    vector<vi> K(n+1, vi(w+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w;j++){
            if(i==0 || j==0) K[i][j] = 0;
            else if(wt[i-1] <= j){
                K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]], K[i-1][j]);
            }
            else {
                K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][w];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
{

    int n, w; cin >> n >> w;
    vi wt(n), vt(n);
    for(int i=0; i<n; i++){
        int temp; 
        cin >> temp; wt[i] = temp;
        cin >> temp; vt[i] = temp;
    }

    ll ans = knap(w, wt, vt, n);
    cout << ans << '\n';

}

    return 0;
}