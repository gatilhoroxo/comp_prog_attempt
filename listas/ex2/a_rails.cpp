#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& numbers){
    int n = numbers.size();
    vector<int> input(n);
    for(int i=0; i<n; i++){ input[i] = i+1; }
    
    bool found = false;
    stack<int> s;

    int i=0;
    while(true) {
        if(s.empty()) n;
        else if(numbers[n-1] == s.top()) {
            s.pop(); 
        }
        else {
            s.push(input[i]);
        }
    }

    if(found) cout << "Yes\n";
    else cout << "No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n=1;
    while(true){
        cin >> n;
        if(n == 0) break;
        else {
            int v;
            vector<int> numbers(n);
            while(true){
                cin >> v;
                if(v == 0) break;
                else {
                    numbers[0] = v;
                    for(int i=1; i<n; i++){
                        cin >> numbers[i];
                    }
                    solve(numbers);
                }
            }
        }
    }
    return 0;
}