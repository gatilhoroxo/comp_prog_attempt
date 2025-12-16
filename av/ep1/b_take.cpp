//travei nesse
//queria usar a list para poder resolver
//take abc //ok
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string linha;
    cin >> linha;

    /*com uma string auxiliar para poder
      ir aos poucos nas partes da string
      e nas suas subpartes que podem formar
      o ABC
    */
    string ans;

    int id=0;
    for(int i=0; i<linha.size(); i++){
        //insere character por character
        ans.push_back(linha[i]);
        id++;
        //se o tamanho da string for maior ou igual a 3
        //e também contem a substring ABC 
        //tira ela logo 
        if(ans.size() >= 3 && ans.substr(id-3, 3) == "ABC"){
            ans.erase(id-3, 3);
            id -= 3;
        }
    }

    //
    cout << ans << '\n';

    return 0;
}