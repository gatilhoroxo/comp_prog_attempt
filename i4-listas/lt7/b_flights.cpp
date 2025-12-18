#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {
    
    int N; cin >> N;
    vector<vi> C(N, vi(N));
    for(auto&i:C){
        for(auto&j:i) 
            cin >> j;
    }

    bool incoherent = false;
    for(int k=0;k<N && !incoherent;k++){
        for(int i=0;i<N && !incoherent;i++){
            for(int j=0;j<N;j++){
                if(C[i][j] > C[i][k] + C[k][j]){
                    incoherent = true;
                    break;
                }
            }
        }
    }

    if(incoherent){
        cout << -1 << '\n';
    } else {
        int removable = 0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                bool needed = true;
                for(int k=0;k<N;k++){
                    if(!(k==i || k==j)) 
                        if(C[i][j] == C[i][k] + C[k][j]){ 
                            needed = false; break; 
                        }
                }
                if(!needed) removable++;
            }
        }

        cout << removable << '\n';
    }

    }

    return 0;
}
