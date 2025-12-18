#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& l, int& busca){
    auto m = lower_bound(l.begin(), l.end(), busca);
    int i = m - l.begin();

    if(*m != busca || i == l.size()){
        return -1; 
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    if(n){
        vector<int> l(n);
        for (int i=0; i<n; i++){
            cin >> l[i];
        }
        //sort(l.begin(), l.end());
        int busca;
        
        while (q--)
        {
            cin >> busca;
            cout << solve(l, busca) << '\n';
        } 
    }   

    return 0;
}