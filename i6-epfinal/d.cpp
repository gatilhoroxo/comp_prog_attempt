//edit distance
//string
#include <bits/stdc++.h>
using namespace std;
#define vec(n) vector<n>
#define ll long long

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    string a, b;
    cin >> a >> b;
    
    int n = a.length();
    int m = b.length();
    
    vec(vec(ll)) dp(n + 1, vec(ll)(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = 1 + min({
                    dp[i-1][j],
                    dp[i][j-1],
                    dp[i-1][j-1]
                });
            }
        }
    }
    
    cout << dp[n][m] << "\n";

    }

    return 0;
}