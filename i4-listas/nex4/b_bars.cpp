//UVA 12455 - Bars
//ok
/*
problema que envolve soma de subsets e encontrar pelo menos uma válida
*/
#include <bits/stdc++.h>
using namespace std;

bool rec(vector<int>& vt, int n, int& p, int idx){
    if(n==0) return true;
    else if(n<0 || idx ==p){
        return false;
    } 
    if(rec(vt, n-vt[idx], p, idx+1)){
        return true;
    } else return rec(vt, n, p, idx+1);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n, p; cin >> n >> p;
        vector<int> vt(p);
        for(auto &i: vt) cin >> i;
        //sort(vt.begin(), vt.end(), greater<int>());
        //for(auto &i: vt) cout << i << ' '; cout << '\n';
        int buff = n;
        bool ok = rec(vt,n,p,0);

        /*for(int wt=0; wt< (1 << p) && !ok; wt++){
            buff=0;
            for(int j=0; j<p; j++){
                if(wt & (1 << j)){
                    buff+=vt[j];
                    if(buff>n) break;
                }
            }
            if(buff == n) ok = true;
        }*/

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return (0);
}
