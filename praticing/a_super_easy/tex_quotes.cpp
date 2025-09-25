/* UVa 00272 - TEX Quotes (replace all double quotes to TEX() style quotes */
//wrong answer :(
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string quote="";
    bool first = false;
    getline(cin, quote);
    for(char c: quote){
        if(c == '"' && !first){ 
            first = true;
            cout << "``";
        } else if(c == '"' && first){
            first = false;
            cout << "''";
        } else {
            cout << c;
        }
    } 
    cout << "\n";

    return 0;
}