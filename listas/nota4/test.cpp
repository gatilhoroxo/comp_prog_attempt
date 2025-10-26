#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        vi vt(n);
        ll MAX = 0;
        for(auto &i: vt) {
            cin >> i;
            MAX = max(MAX, (ll)i); // MAX como ll
        }

        // Busca binária no seu estilo
        ll low = 1;
        ll high = MAX + x;
        ll ans = 1;

        while(low <= high){
            ll mid = low + (high - low)/2;
            ll w = 0;
            for(int i=0;i<n;i++){
                if(mid > vt[i]){
                    w += (mid - vt[i]);
                    if(w > x) break; // poda para não somar desnecessário
                }
            }
            if(w <= x){
                ans = mid;   // mid é válido
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
