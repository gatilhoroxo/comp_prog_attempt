#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    int buff= a & b;
    bool check=0;
    if(buff == 0){ cout << "true\n"; } 
    else { cout << "false\n"; }

    return 0;
}