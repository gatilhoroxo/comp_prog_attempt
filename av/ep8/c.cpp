//counting divisors
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define MAX 1'000'001
using ii = pair<int,int>;

// --------------- fatoração em primos ---------------
map<int,ii> fatoracao_prima(int n){
    map<int,ii> frequencias;
    int temp = n;

    if(temp <= 1) return frequencias;
    frequencias[2].first = 2;
    while(temp % 2 == 0){
        frequencias[2].second++;
        temp = temp / 2;
    }

    for(int i = 3; i * i <= temp; i += 2){
        while(temp % i == 0){
            frequencias[i].first = i;
            frequencias[i].second++;
            temp = temp/i;
        }
    }

    if(temp > 1){
        frequencias[temp]={temp,1};
    }

    return frequencias;
}

int contar_divisores(int n){
    if(n <= 0) return 0;
    map<int,ii> frequencias = fatoracao_prima(n);

    int totaldivisores = 1;
    for(auto &par : frequencias){
        totaldivisores *= (par.second.second + 1);
    }
    return totaldivisores;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    /*
    //contar a quantidade de divisores desse numero
    //guardar todas as quantidades dos divisores em um vetor
    vec(int) vt(MAX,1);
    vt[2] = 2;
    for(int i=2; i < MAX;i++){
        
    }
    */
    

    int t; cin >> t; while(t--)
    {

    int n; 
    cin >> n;
    cout << contar_divisores(n) << '\n';

    }

    return 0;
}