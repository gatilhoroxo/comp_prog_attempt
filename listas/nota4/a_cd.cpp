//CD
//i only started this
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n){
        int musics; cin >> musics;
        vector<int> vt(musics);
        for(auto & i: vt) cin >> i;
        sort(vt.begin(), vt.end());
        for(int i=0; i<musics; i++){
            //dont know what to put here
        }
    }

    return 0;
}