#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q; 
    cin >> n >> k >> q;
    vector<int> points(n, k);
    int rodadas[q];
    for(int i=0; i<q; i++){
        cin >> rodadas[i];
        points[rodadas[i]-1] += 1;
    }
    /*
    for(auto i: points){
        cout << i << " ";
    }
    cout << "\n";
    */
    
    for(auto p:points){
        if(p>q) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}