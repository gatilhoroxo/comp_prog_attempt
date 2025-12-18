//UVa 00621 - Secret Research
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >>n;
    while(n--){
        string s;
        cin >> s;
        if(s == "1" || s=="4" || s=="78") cout << '+';
        else if(s[s.size()-1] == '5' && s[s.size()-2] == '3') { cout << '-';} 
        else if(s[s.size()-1] == '4' && s[0] == '9') {cout << '*';}
        else { cout << '?';}
        cout << '\n';
    }

    return 0;
}