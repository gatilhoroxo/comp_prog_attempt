//basic code
#include <bits/stdc++.h>
using namespace std;
#define vec(n) vector<n>
#define MAX 51
void INPUT(int& k, string& a, string& b){
    string entrada, num;
    bool start_a=false, start_b=false, start_k=false;
    getline(cin,entrada);
    for(auto&c:entrada){
        if(start_a && c != '+') a+=c;
        else if(start_b && c != ')') b+=c;
        else if(start_k) num+=c;
        
        if(c == '('){
            start_a = true;
        } else if(c == '+'){
            start_a = false;
            start_b = true;
        } else if(c == ')'){
            start_b = false;
        } else if(c == '^'){
            start_k = true;
        }
    }
    k=atoi(num.c_str());
}

vec(vec(int)) pascal = 
{
    {1},
    {1, 1},
    {1, 2, 1},
    {1, 3, 3, 1},
    {1, 4, 6, 4, 1}
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vec(vec(int)) vt_pascal(MAX, vec(int)(MAX, 0));
    for(int i=0; i<MAX; i++){
        for(int j=0; j<=i; j++){
            if(i==0) vt_pascal[i][j] = 1;
        }
    }
    int t; 
    cin >> t;
    cin.ignore();
    for(int i=0;i<t; i++){
        int k;
        string a, b; 
        INPUT(k, a, b);
        //fazer logica para os coeficientes binomiais
        int exp_a=k, exp_b=0, coef=0;
        cout << "Case "<< i+1 << ": ";
        cout << "(" << a << '+' << b << ")^" << k << '\n';

    }

    return 0;
}