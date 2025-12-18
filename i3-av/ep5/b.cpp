//frog 2
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;
using vl = vector<ll>;
using vll = vector<vl>;

//greedy or dp solution
//cacheiro viajante

ll rec(vi& vt, int& k, int nivel, int pedA, int pedV, ll sum){
    if(pedA >= vt.size() || pedV >= vt.size()) return sum;
    else {
        ll minimo=rec(vt, k, 0, pedV, pedV+1, sum);
        for(int i=0; i<k; i++){
            ll m = rec(vt, k, nivel+i, pedA, pedV+i, sum+(abs(vt[pedA] - vt[pedV])));
            minimo = min(m, minimo);
        }
        return minimo;
    }
}

int mainbase(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n, k; 
    cin >> n >> k;
    vi h(n);
    for (auto&i: h) cin >> i;

    ll ans = rec(h, k, 0, 0, 1, 0);

    cout << ans << '\n';

    }
    return 0;
}

/*===============================================================*/


ll knap(int w, vl wt, int n){
    vector<vi> K(n+1, vi(w+1));
    for(int i=0; i<=n; i++){
        for(int j=0; j<=w;j++){
            if(i==0 || j==0) K[i][j] = 0;
            else if(wt[i-1] <= j){
                K[i][j] = max(K[i-1][j-wt[i-1]], K[i-1][j]);
            }
            else {
                K[i][j] = K[i-1][j];
            }
        }
    }
    return K[n][w];
}

ll recv2(vi& vt, int& k, int pa){
    if(pa == vt.size()) return LLONG_MAX;
    vl vx(k);
    for(int i=0; i<k; i++){ vx[i] = abs(vt[pa] - vt[i]); } 
    int min = knap(1, vx, k);

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n, k; 
    cin >> n >> k;
    vi h(n);
    for (auto&i: h) cin >> i;

    vll sum(n,vl(n,-1));
    ll ans = recv2(h, k, 0);

    cout << ans << '\n';

    }
    return 0;
}
