#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    set<int> num;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        num.insert(x);
    }
    cout << num.size();

    return 0;
}