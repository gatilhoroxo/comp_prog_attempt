#include <bits/stdc++.h>
using namespace std;

void solve(int& l, queue<int>& left, queue<int>& right){
    int ans = 0;
    
    while(true){
        if(left.empty() && right.empty()){
            break;
        }
        /*esquerda*/
        if(left.empty()){
            ans++;
        } 
        else {
            int soma = left.front();
            if(soma < l){
                
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int c;
    cin >> c;
    while(c--){
        int l, m;
        cin >> l >> m;
        queue<int> left;
        queue<int> right;

        for(int i=0; i<m; i++){
            int len; 
            string sense;
            cin >> len >> sense;
            if(sense == "left"){
                left.push(len);
            }
            else {
                right.push(len);
            }
        }
        int ans=0;

        /*code is here*/
        solve(l, left, right);

        cout << ans << '\n';
    }

    return 0;
}