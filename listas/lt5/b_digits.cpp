//Removing digits
#include <bits/stdc++.h>
using namespace std; 
/*resolver o ponto flutuante*/

vector<int> dp(1000001);

int rec(int n){ 
    if(n==0) return 0;
    if(dp[n] != -1) return dp[n];
    int ans = INT_MAX;
    int resto = n;
    while(resto>0){
        int d = resto % 10;
        resto /= 10;
        if(d>0) ans = min(ans, 1+rec(n - d));
    }
    return dp[n]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >>t; while(t--)
    {

    int n; cin >> n;
    dp.assign(1000001, -1);
    cout << rec(n) << '\n';

    }
}