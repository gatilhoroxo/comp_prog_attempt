//UVa 11727 - Cost Cutting
//com uma dica
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    for(int i=1; i<=t; i++){
        vector<int> vt(3); 
        for(auto &j: vt) cin >> j;
        sort(vt.begin(), vt.end());
        cout << "Case " << i << ": " << vt[1] << '\n';
    }

    return 0;
}