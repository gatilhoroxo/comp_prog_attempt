//UVA 11742 - Social Constraints  
//site caiu
/*
problema de permutação e encontrar a quantidade válida para certas restrições
*/
#include <bits/stdc++.h>
using namespace std;

long long fat(int n){
    long long fat=1;
    for(int i=0; i<n; i++) { fat*=(n-i); }
    return fat;
}
int fact(int n) {
    if(n == 1) return 1;
    return n * fact(n-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        int n, m; 
        cin >> n >> m;
        if(n == 0 && m == 0){ break; }
        vector<int> vt(n);
        for(int i=0; i<n; i++) vt[i] = i;
        vector<int> a(m), b(m), c(m); 
        for(int i=0; i<m; i++) {
            cin >> a[i] >> b[i] >> c[i];
        }
        int ans=0;
        if(m>0) {
            do {
                //for(auto &i: vt) cout << i << ' '; cout << '\n';

                int is_correct = 0;
                for(int k=0; k<m; k++){
                    int primero = -1, cnt=0;
                    bool found_primero=false;
                    //
                    for(auto &i: vt){
                        if(!found_primero){
                            if(a[k] == i || b[k] == i) { 
                                primero = i; 
                                found_primero=true;
                            }
                        } else {
                            cnt++;
                            if(a[k] == i || b[k] == i){ break; }
                        }
                    }
                    // cout << cnt << '\n';
                    if(c[k] > 0){
                        if(cnt <= c[k]){ is_correct++; } 
                        else { break; }
                    } else {
                        if(cnt >= abs(c[k])){ is_correct++; } 
                        else { break; }
                    }
                }
                if(is_correct==m) ans++;
            } while(next_permutation(vt.begin(), vt.end()));
        } else { ans = fact(n); }
        cout << ans << '\n';

    }

    /*outra forma de resolver é fazer a permutação dos adolescentes e ver se cada permutação está cumprindo as restrições da socialização deles*/

    return 0;
}