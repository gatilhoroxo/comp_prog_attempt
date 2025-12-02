//feito
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n){
        if(n == 0) break;
        bitset<32> nbit(n);
        //cout << nbit << '\n';
        int sum=0;
        int inicio=-1;
        string s;
        for(int i=31; i>=0; i--){
            if(nbit[i] && inicio==-1) inicio = i;
            if(inicio!=-1) {
                if(nbit[i]) s+='1';
                else s+='0';
            }
            sum+=nbit[i];
        }
        cout << "The parity of " << s << " is " << sum << " (mod 2).\n";
    }

    return 0;
}