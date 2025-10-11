// UVa 01237 - Expert Enough *
/*
 * with help https://github.com/vmmc2/Competitive-Programming/blob/master/UVA%2001237%20-%20Expert%20Enough%3F.cpp 
 * está recebendo resposta errada (??)
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
        map<string, pair<int,int>> mapp;
        for(int i=0; i<d; i++){
            string s; int l, h;
            cin >> s >> l >> h;
            if(mapp.find(s) == mapp.end()){
                mapp[s] = {l,h};
            } else {
                if(l < mapp[s].first){
                    mapp[s].first = l;
                }
                if(h > mapp[s].second){
                    mapp[s].second = h;
                }
            }
        }

        int q; cin >> q;
        string none = "UNDETERMINED";
        while(q--){
            int val; cin >> val;
            vector<string> ans;
            for(auto it : mapp){
                if(val >= it.second.first && val <= it.second.second){
                    ans.push_back(it.first);
                }
            }
            if(ans.size() == 1) cout << ans[0];
            else cout << none;
            /*else {
                int lastmin=15<<27, 
                    lastmax=15<<27, 
                    idx=0;
                auto it = ans.begin();
                for(auto i:ans){
                    int abslow = abs(val - mapp[i].first),
                        abshigh = abs(val - mapp[i].second);
                    if(abslow < lastmin) {
                        lastmin = abslow;

                    } 
                    if(abshigh < lastmax) {

                    }
                }
            }*/
            if(q) cout << '\n';
        }
    }

    return 0;
}