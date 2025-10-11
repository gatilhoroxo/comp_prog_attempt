// UVa 01237 - Expert Enough *
/*
 * 
*/

#include <bits/stdc++.h>
using namespace std;

bool compMenor(const pair<string, int>& a, const pair<string, int>& b){ return a.second < b.second; }
bool compMaior(const pair<string, int>& a, const pair<string, int>& b){ return a.second > b.second; }

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int d; cin >> d;
        vector<pair<string, int>> vtlow(d), vthigh(d);
        for(int i=0; i<d; i++){
            string s; int l, h;
            cin >> s >> l >> h;
            vtlow[i] = make_pair(s, l);
            vthigh[i] = make_pair(s, h);
        }
        sort(vtlow.begin(), vtlow.end(), compMenor);
        sort(vthigh.begin(), vthigh.end(), compMaior);
        int q; cin >> q;
        string none = "UNDETERMINED\n";
        while(q--){
            int val; cin >> val;
            if(val < vtlow[0].second || val > vthigh[0].second) {
                cout << none;
            } else {
                pair<int,int> lastmin=make_pair(0,15<<27), 
                            lastmax=make_pair(0,0);
                for(int i=0; i<d; i++){
                    int itmin = abs(val - vtlow[i].second);
                    int itmax = abs(val - vthigh[i].second);
                    if(itmin < lastmin.second) {
                        lastmin = make_pair(i, itmin);
                    }
                    if(abs(val - vthigh[i].second) > lastmax.second){
                        lastmax = make_pair(i, itmax);
                    }
                    if(lastmin.second >= lastmax.second){
                        break;
                    }
                }
                cout << ((lastmin.second < lastmax.second) ? vtlow[lastmin.second].first : vthigh[lastmax.second].first) << '\n';
            }
        }
    }

    return 0;
}