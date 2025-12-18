// UVa 11364 - Parking
//lembrei um pouco do divide and conquer
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;
    while(t--){
        int s; cin >> s;
        vector<int> vt(s);
        for(auto &i: vt) cin >> i;
        sort(vt.begin(), vt.end());
        int l = vt[0];
        int r = vt[s-1];
        cout << (r-l)*2 <<'\n';
    }

    return 0;
}