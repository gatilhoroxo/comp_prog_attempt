#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int cut_odd = 0;
        int minor_odd = 2'000'000'000;
        long long int soma=0;
        vector<int> filds(n);
        for(int i=0; i<n; i++){ 
            cin >> filds[i];
            if(filds[i] %2 != 0){
                cut_odd++;
                minor_odd = min(minor_odd, filds[i]);
            }
            soma += filds[i];
        }
        if(cut_odd != 0){ 
            if(cut_odd % 2 == 0){ soma -= minor_odd; }
            cout << soma << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}
