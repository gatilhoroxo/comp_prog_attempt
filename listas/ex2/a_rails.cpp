#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& vagoes){
    int n = vagoes.size();
    vector<int> input(n);
    for(int i=0; i<n; i++){ input[i] = i+1; }
    bool found = false;

    stack<int> s;
    while(true) {
        if(s.empty()) n;
        else if(vagoes[n-1] == s.top()) {
            
        }
    }

    if(found) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while(true){
        cin >> n;
        if(n == 0) break;
        else {
            int v;
            while(true){
                cin >> v;
                vector<int> vagoes(n);
                if(v==0) break;
                else {
                    vagoes[0] = v;
                    for(int i=1; i<n; i++){
                        cin >> vagoes[i];
                    }
                }

                solve(vagoes);

            }
        }
    }

    return 0;
}