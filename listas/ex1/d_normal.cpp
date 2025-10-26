#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    string s;

    //pwq
    while(t--){
        cin >> s;
        int n=s.size();
        string ans = s;
        int j=0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == 'p'){
                ans[j] = 'q';
                j++;
            }
            else if(s[i] == 'q'){
                ans[j] = 'p';
                j++;
            }
            else {
                ans[j] = 'w';
                j++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}