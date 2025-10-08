#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        map<int, int> a;
        for(int i=0; i<n; i++){
            int orbit; cin >> orbit;
            a[orbit] += 1;
        }
        vector<int> v(n);
        int tamV=0;
        for(auto m : a){
            v[tamV++] = m.second;
        }

        priority_queue<int, vector<int>> pq(v.begin(), v.end());

        int ans = 0;
        while(!pq.empty()){
            if(pq.top() > c){
                pq.pop();
                ans+=c;
            } else {
                ans += pq.top();
                pq.pop();
            }
        }
        cout << ans << '\n';
        
        //while(!pq.empty()){ cout << pq.top() << ' ' << ' '; pq.pop(); } cout << '\n';

    }

    return 0;
}