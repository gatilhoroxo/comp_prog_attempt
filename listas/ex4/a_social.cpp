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
        if(m != 0){
            vector<int> a(m), b(m), c(m);
            for(int i=0; i<m; i++) { 
                cin >> a[i] >> b[i] >> c[i]; 
            }
        } else {
            cout << fat(n) << endl;
        }
        
    }

    /*outra forma de resolver é fazer a permutação dos adolescentes e ver se cada permutação está cumprindo as restrições da socialização deles*/

    return 0;
}