//1d eraser
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n, k, ans=0; 
    string s;
    cin >> n >> k >> s;
    
    for(int i=0; i<n; i++){
        if(s[i] == 'B'){
            ans++;
            for(int j=i; j<k+i && j<n; j++){
                s[j] = 'W';
            }
        }
    }

    cout << ans << '\n';

    }

    return 0;
}