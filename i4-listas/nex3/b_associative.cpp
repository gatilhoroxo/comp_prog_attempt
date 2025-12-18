#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    cin >> n;
    long long k, v;
    map<long long, long long> m;
    while(n--){
        int op;
        cin >> op >> k;
        if(op == 0){
            cin >> v;
            m[k] = v;
        } else {
            cout << m[k] << "\n";
        }
        
    }
}