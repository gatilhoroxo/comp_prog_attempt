#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    stack<int> estacao;
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