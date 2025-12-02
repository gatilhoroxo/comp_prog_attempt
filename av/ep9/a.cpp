//foreign language
#include <bits/stdc++.h>
using namespace std;
#define vec(n) vector<n>
#define ll long long


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int tc; cin >> tc; while(tc--)
    {

    int n, m;
    ll cost_add, cost_del, cost_replace;
    cin >> n >> m;
    cin >> cost_add >> cost_del >> cost_replace;

    string s, t;
    cin >> s >> t;
    

    vec(vec(ll)) dp(n + 1, vec(ll)(m + 1, 0));
    
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + cost_del;
    }
    for (int j = 1; j <= m; j++) {
        dp[0][j] = dp[0][j-1] + cost_add;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min({
                    dp[i-1][j] + cost_del,
                    dp[i][j-1] + cost_add,
                    dp[i-1][j-1] + cost_replace
                });
            }
        }
    }
    
    cout << dp[n][m] << "\n";

    }

    return 0;
}