//
#include <bits/stdc++.h>
using namespace std;

//calcular a media de ouro de cada
//ver a diferenca de cada uma 
//conta quantos tem menos que a média
//essas são as pessoas infelizes
//como subir a média para que metade mais um esteja infeliz

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> vt(n);
        int soma=0, maximo=0;
        for(auto&i:vt) {
            cin >> i;
            soma+=i;
        }
        sort(vt.begin(), vt.end());
        maximo = vt[n-1];
        float media=soma/n;
        int diferenca=0;
        int happy=0;
        for(int i=0; i<n; i++){
            if(vt[i]>=media/2){ happy++;} 
        }
        //cout << "feliz: " << happy << endl;
        if(n == 1 || n == 2) cout << -1 << '\n';
        else if(happy < n/2+1) cout << 0 << '\n';
        else {
            int half = n/2;
            int gold=soma;
            while(true){
                gold++; 
                media = (gold+soma)/n;
                int unhappy=0;
                for(int i=0; i<n; i++){
                    if(vt[i]<media/2) {
                        unhappy++;
                    }
                } 
                if(unhappy >= half) { break; }
            }
            cout << gold << '\n';
        }
        //cout << "media: " << media << endl;
        //cout << "total: " << soma << endl;
    }

    return 0;
}