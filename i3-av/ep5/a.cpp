//1d eraser
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;

    while(t--){
        int n, k, ans=0;
        string s; 
        cin >> n >> k >> s;
        //solucao direta
        //foi kk em 12min... mds
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'B'){
                ans++;
                for(int j=i; j<k; j++){
                    s[j] = 'W';
                }
                i+=(k-1);
            }
        }
        //solucao greedy ou dp (pensando)
        cout << ans << '\n';
    }

    return 0;
}