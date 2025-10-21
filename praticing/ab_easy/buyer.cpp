//UVa 10114 - Loansome Car Buyer
//ta dando algum erro
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int months, ndepreciation; 
        float payment, amount;
        cin >> months >> payment >> amount >> ndepreciation;
        if(months<0) break;
        vector<pair<int,float>> dep(ndepreciation);
        for(auto&i: dep){ cin >> i.first >> i.second; } 
        //for(auto&i:dep){ cout << i.first << ' ' << i.second << '\n';}
        float money=amount;
        float price_car=amount;
        int j=0; int ans=0;
        for(int i=0; i<months; i++){
            money-=payment;
            if(dep[j].first < i) { j++;}
            price_car = price_car*(1-dep[j].second);
            if(money<price_car) { ans=i+1; break;}
        }
        cout << ans << '\n';
    }

    return 0;
}