//distinct numbers
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    int n; cin >> n;
    map<int,int> numbers;
    for(int i=0;i<n; i++){
        int entrada; 
        cin >> entrada;
        numbers[entrada]+=1;
    }

    cout << numbers.size() << "\n";


    }

    return 0;
}