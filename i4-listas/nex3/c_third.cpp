#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end());

        int tmp1, tmp2;
        while(pq.size() != 1){
            tmp1 = pq.top(); pq.pop();
            tmp2 = pq.top(); pq.pop();
            pq.push(tmp1 + tmp2 - 1);
        }
        cout << pq.top() << '\n';
    }

    return 0;
}