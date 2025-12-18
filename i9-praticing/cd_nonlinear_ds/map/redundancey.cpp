//UVa 00484 vjugde - the departament of redundancy departament
//passou de segunda
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    map<int,int> m;
    vi v;
    int n;
    int counter=0;
    while((cin >> n)){
        m[n] = m[n]+1;
        if(m[n] == 1){
            v.push_back(n);
            counter++;
        }
    }

    string saida = "";
    for(auto i : v){
       saida = saida + to_string(i) + ' ' + to_string(m[i]) + '\n';
    }
    cout << saida;

    return 0;
}