//braga1s problem
#include <bits/stdc++.h>
using namespace std;
 
#define vec(n) vector<n>
#define MAX 10'000'001
using ii = pair<int,int>;

vec(bool) crivo(){
    vec(bool) primos(MAX, true);
    primos[0] = primos[1] = false;
    for(int i=2; i<MAX;i++){
        if(primos[i] && (long long)i*i <= MAX) {
            for(int j=i+i; j<MAX; j+=i){
                primos[j] = false;
            }
        }
    }
    return primos;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //contar a quantidade de primos de dois até esse numero
    //guardar todas as quantidades dos primos em um vetor
    vec(bool) primos = crivo();
    vec(int) vt(MAX,0);
    vt[3] = 1;
    for(int i=4; i<MAX;i++){
        vt[i] = vt[i-1] + int(primos[i-1]);
    }
    //cout << primos[23] << ' ' << vt[23] << "\n";

    int t; cin >> t; while(t--)
    {
        int n; 
        cin >> n;
        //ver se ele é primo e se a quantidade de primos dele até 2 é primo tbm (sem incluir ele)
        bool ans = false;
        if(primos[n]){
            ans = true;
            for(int i=vt[n]; i>=1 && ans;i=vt[i]){
                //cout << i << ' ';
                if(!primos[i]){
                    ans = false;
                }
            }
            //cout << '\n';
        }
 
        if(ans) cout << "yes\n";
        else cout << "no\n";
    }   
 
    return 0;
}