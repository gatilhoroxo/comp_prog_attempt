//round trip
//
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> vt;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        vt.push_back({c,{a,b}});
        vt.push_back({c,{b,a}});
    }


    return 0;
}
