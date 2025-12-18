//UVa 12250 - Language Detection
//é só um switch case
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string st;cin >> st;
    for(int i=1;st != "#"; i++){
        cout << "Case " << i << ": ";
        if(st == "HELLO") cout << "ENGLISH";
        else if(st == "HOLA") cout << "SPANISH";
        else if(st == "HALLO") cout << "GERMAN";
        else if(st == "BONJOUR") cout << "FRENCH";
        else if(st == "CIAO") cout << "ITALIAN";
        else if(st == "ZDRAVSTVUJTE") cout << "RUSSIAN";
        else cout << "UNKNOWN";
        cout << '\n';

        cin >> st;
    }

    return 0;
}