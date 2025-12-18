#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n=15;
    vector<int> s(n);
    s = {4, 11, 5, 2, 4, 
         8, 3, 4, 6, 8, 
         4, 7, 9, 11, 34};

    sort(s.begin(), s.end());
    for(auto i : s){
        cout << i << ' ';
    } cout << '\n';
    
    //contagem de um ou mais pares em um array
    /*
    int dif = 0, old = -1, cnt=0;
    for(int i=0; i<n; i++){
        if(dif == s[i] && dif != old){
            cnt++;
            dif = 0;
            old = s[i];
        } else dif = s[i];
    }
    cout << cnt << '\n';
    //*/

    /*
    //encontrar um a e b no s que sua soma seja igual a v;
    int v=19;
    int a=0, b=0;
    int i=0,j=0;
    for(i=0; i<n-1; i++){
        a = s[i];
        //maneira mais direta
        for(j=i+1; j<n; j++){
            b = s[j];
            if((a + b) >= v){
                break;
            }
        }
        //ou a alternativa abaixo
        b = v - a;
        b = *lower_bound(s.begin()+i+1, s.end(), b);
        //
        if(a+b==v) break;
    }
    cout << i << ':' << a << ' ' << j << ':'  << b << '\n';
    //*/
    /*printar os valores em s, que estão entre [a..b]
    int a=5, b = 10;
    for(int i=0; i<n; i++){
        if(s[i] >= a) cout << s[i] << ' ';
        if(s[i] == b || i == n-1) break;
        if(s[i+1] > b) break;
    }
    cout << '\n';
    //*/

    //*encontrar o tamanho do mais 
    // longo, crescente e continuo sub-array em S

    //encontrar a média(50%) de s
    //assumindo que 'n' é ímpar

    return 0;
}