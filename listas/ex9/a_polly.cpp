//basic code
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

void print_vt(vi vt){
    for(auto&i:vt){ 
        cout << i << ' ';
    } cout << endl;
}

vi processar_coef(string& s){
    vi vt;
    string buff="";
    char sinal = '0';
    s = s + ' ';
    for(auto&c:s){
        //cout << c << ' ' << buff << endl;
        if(c == ' ') {
            int temp=1;
            if(sinal == '-'){
                temp = -1;
            }
            vt.push_back(atoi(buff.c_str())*temp);
            buff = "";
            sinal = '0';
        }
        else if(c=='-') {
            sinal=c;
        }
        else if('9'>= c && c >='0') {
            buff=buff+c;
        }
    }
    //print_vt(vt);
    return vt;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string entrada;
    while(getline(cin,entrada)){
        //cout << entrada << endl;
        //processamento da primeira linha
        vi vt = processar_coef(entrada);
        //processamento da segunda linha
        getline(cin,entrada);
        vi xt = processar_coef(entrada);
        //print_vt(vt);
        //print_vt(xt);

    }

    return 0;
}