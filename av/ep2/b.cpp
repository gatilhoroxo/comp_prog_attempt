#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    //int t; cin >> t; while(t--)

    {

    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());
    //i dentro de j
    //caixa i menor que caixa j
    //i nao pode por dentro de outra caixa
    //j nao  pode conter outras caixas    
    int top = pq.top(); pq.pop();
    int caixasP=0;
    int ans=0;
    int i=0;
    while(!pq.empty()){
        i++;
        if(pq.top() > top){
            if(caixasP == 0) {
                top = pq.top();
            } else {
                caixasP--; 
                pq.pop(); 
            }
        }
        else if(pq.top() == top) {
            ans++;
            caixasP++;
            pq.pop();
        } 
    }
    
    cout << ans << '\n';

    }
    return 0;
}