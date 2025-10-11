//UVa 00927 - Integer Sequence from ...
/* 
 * solução de https://tanjim131.github.io/2020-06-03-uva-927/
 * ainda não entendi bem o porque que funciona
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int c; cin >> c;
    int t, d, k;
    while(c--){
        cin >> t; t++;
        vector<int> coef(t);
        for(int i=0; i<t; i++)
            cin >> coef[i]; 
        cin >> d >> k;
        int count = 0;
        int n=1;
        long long a_n = 0;
        /*while(count < k){
            a_n = 0;
            for(int i=0; i<t; i++){
                a_n += coef[i] * pow(n, i);
            }
            count += n*d;
            n++;
        }*/
        //*
        n = ceil((-1 + sqrt(1 + (8 * k /d))) /2);
        a_n = 0;
        for(int i=0; i<t; i++){
            a_n += coef[i] * pow(n, i);
        }
        //*/
        cout << a_n << '\n';
    }

    return 0;
}