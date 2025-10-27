//Apple Division
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;


ll rec(vi& vt, ll l, ll r, int i){
    if(i==vt.size()) 
        return llabs(l-r);
    else {
        ll m1 = rec(vt, l+vt[i], r, i+1);
        ll m2 = rec(vt, l, r+vt[i], i+1);
        return min(m1, m2);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vi vt(n);
    ll total=0;
    for(auto&i:vt) {
        cin >> i;
        total+=i;
    }
    ll ans = rec(vt, 0, 0, 0);
    //cout << sx << ' ' << sy << '\n';
    cout << ans << '\n';

    return 0;
}