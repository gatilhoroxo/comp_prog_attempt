#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n=0, s=0, buf=0;
    bool pot = false;
    
    /*mod de um valor s por n
    cin >> s >> n;
    cout << (s >> n) << '\n';
    //ok*/

    /*s eh uma potencia de 2
    cin >> s;
    pot = false;
    int buf=0;
    for(int i=1; i<32 && !pot; i++){
        buf = s & (1 << i);
        if(s == buf){
            pot = true;
        }
    }
    cout << buf << ' ' << (pot ? "true" : "false") << '\n';
    //ok*/

    /*desligar o último bit 1
    cin >> s;
    pot=false; 
    for(int i=0; i<32 && !pot; i++){
        buf = s & (1 << i);
        if(buf != 0){
            pot = true;
            s = s & ~(1 << i);
        }
    }
    cout << s << '\n';
    //ok*/

    /*desligando a ultima sequencia de bits 1
    cin >> s;
    pot=false;
    int buf;
    for(int i=0; i<32 && !pot; i++){
        buf = s & (1 << i);
        if(buf != 0){
            pot = true;
            while(buf != 0 && i<32){
                buf = s & (1 << i);
                if(buf != 0) s = s & ~(1 << i);
                i++;
            }
        }
    }
    cout << s << '\n';
    // */

    //*ligando a ultima sequencia de bits 0
    int s;  cin >> s;
    int ind=0;
    for(int i=0; i<32 && !pot; i++){
        buf = s & (1 << i);
        if(buf != 0){
            pot = true;
            ind = i;
        }
    }
    buf=s;
    for(int i=0; i<=ind;i++) buf = buf | (1 << i);
    cout << buf << '\n';
    //*/

    //solucione o UVa 11173 - grey codes 
    // com uma linha de bit mani. expression

    //agora o inverso
    //dado um gray code, qual a posicao k
    //usando bit manipulado
    
    //*printando a saida em bits
    bitset<sizeof(int)*8> bits(buf);
    for(int i=8; i>=0;i--){
        cout << bits[i];
    }
    cout << '\n';
    //*/
    
}