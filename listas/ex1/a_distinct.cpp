#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=0, ans=0;
    cin >> n;
    vector<int> l(n);
    for(int i=0; i<n; i++){
        cin >> l[i];
    }
    
    sort(l.begin(), l.end());
    /*
    for(int i=0; i<n; i++)
        cout << l[i] << ' ';
    cout << "\n";
    */
    ans++;
    for(int i=0; i<n-1; i++){
        if(l[i] != l[i+1]){
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}