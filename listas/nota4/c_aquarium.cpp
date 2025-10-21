//Building an Aquarium CodeForces - 1873E
#include <bits/stdc++.h>
using namespace std;
using vi = vector<long long>;
using ll = long long;

ll MAX=0;
/*
int rec(vi& vt, int x, int h){
    int w=0;
    for(auto&i:vt){ w+=max(0,h-i); }
    if(w>x){ return h-1; }
    else if(w==x) { return h; }
    return (rec(vt, x, h+1));
}
*/

ll bb(vi& vt, ll& x){
    ll low=1;
    ll high = MAX + x;
    ll ans=1;
    while(low<=high){
        ll mid = (high+low)/2;
        ll w=0;
        for(auto&i:vt) {
            if(mid > i) {
                w+=(mid-i);
                if(w>x) break;
            }
        }
        if(w<=x) {
            ans = mid;
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        ll n, x; 
        cin >> n >> x;
        vi vt(n);
        MAX=0;
        for(auto&i: vt) {
            cin >> i;
            MAX = (MAX < i ? i : MAX);
        }
        cout << bb(vt, x) << endl;
    }

    return 0;
}