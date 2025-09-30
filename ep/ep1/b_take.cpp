//no
#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string linha;
    cin >> linha;

    list<char> ans;

    while(true){
        int id = linha.find("ABC");
        linha.erase(id);
        linha.erase(id+1);
        linha.erase(id+2);
        

    }

    for(char c: ans){
        cout << c;
    }
    cout << '\n';
    

    return 0;
}