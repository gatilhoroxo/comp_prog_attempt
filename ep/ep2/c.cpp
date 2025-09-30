#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {
    
    int n, x; cin >> n >> x;
    multiset<int> ms;
    map<int,int> maping;
    for(int i=0;i<n;i++) { 
        int num; cin >> num; 
        ms.insert(num); 
        maping[num] = i+1;
    }
    int finded=0;
    int first=0;
    for(auto value: ms){
        finded = (*ms.find((x-value)));
        if(finded+value == x){
            first = value;
            break;
        }
    }

    if(finded && first){
        cout << maping[finded] << maping[first] << '\n'; 
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    }
    return 0;
}
