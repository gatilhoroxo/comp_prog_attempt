#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int knap(int w, vi wt, vi& val, int n){
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

int knapsack(int W, vector<int> &wt, vector<int> &val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],  
                    dp[i - 1][w]                           
                );
            } else {
                dp[i][w] = dp[i - 1][w]; 
            }
        }
    }

    return dp[n][W];
}


int main(){
    
}