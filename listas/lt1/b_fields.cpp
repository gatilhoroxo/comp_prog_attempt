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

        long long int soma=0;
        vector<int> filds(n);
        vector<int> odd_filds;
        
        for(int i=0; i<n; i++){ 
            cin >> filds[i];
            if(filds[i] % 2 != 0){
                odd_filds.push_back(filds[i]);
            } else {
                soma += filds[i];
            }
        }
        
        sort(odd_filds.begin(), odd_filds.end());
        
        if(odd_filds.size() != 0){ 
            int id = floor(odd_filds.size()/2);
            for(int i=id; i< odd_filds.size(); i++){
                soma += odd_filds[i];
            }
            cout << soma << '\n';
        }
        else { 
            cout << 0 << '\n';
        }

    }

    return 0;
}
