//Boxes Packing CodeForces - 903C
//travei nesse no meio
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
    int ans=n;
    vector<int> vt;
    while(true){
        int lasttop = pq.top(); pq.pop();
        if(pq.empty()) break;
        else if(pq.top() > lasttop) { ans--; } 
        else if(pq.top() == lasttop) {
            vt.push_back(lasttop);
            if(!vt.empty()) 
                if(vt.front() < pq.top()){
                    vt.erase(vt.begin());
                    ans--;
                }
        } 
    }
    
    cout << ans << '\n';

    }
    return 0;
}