#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string atrib, cat;
        map<string,int> categoria;
        for(int i=0; i<n; i++){
            cin >> atrib >> cat;
            categoria[cat]++;
        }

        int mul=1;
        for(auto it : categoria){
            mul *= (it.second + 1);
        }

        cout << mul - 1 << '\n';
    }

    
    return 0;
}