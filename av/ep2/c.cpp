//Sum of Two Values CSES - 1640
//
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {
    
    int n, x; cin >> n >> x;
    int finded=0;
    int first=0;
    map<int,int> mapa;
    for(int i=0;i<n;i++) { 
        int num; cin >> num; 
        if(num<x){
            if(mapa[x-num] == 0){ 
                mapa[num] = i+1; 
            } else {
                cout << mapa[x-num] << ' ' << i+1 <<'\n';
                finded = true;
                break;
            }
        }
    }

    if(!finded){ cout << "IMPOSSIBLE\n"; }

    }
    return 0;
}
