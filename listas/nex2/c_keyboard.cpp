#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(cin >> s){
        list<char> l;
        bool begin = false;
        auto it = next(l.begin(), 1);
        for(int i=0; i<s.size(); i++){
            char& c = s[i];
            if(c == '['){
                begin = true;
                it = l.begin();
            } else if(c == ']'){
                begin = false;
                it = l.end();
            } else {
                l.insert(it, c);
            }
        }
        for(auto c : l){
            cout << c;
        }
        cout << '\n';
    }

    return 0;
}