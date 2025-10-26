//Dominator
#include <bits/stdc++.h>
using namespace std;
using vb = vector<bool>;
using ll = long long;
using vbb = vector<vb>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >>t;
    while(t--){
        int n; cin >> n;
        vbb vt(n, vb(n));
        for(auto&i:vt){ 
            for(int j=0; j<n; j++){ 
                int ent;cin >> ent;
                i[j]=ent; }}
        
    }

    return 0;
}