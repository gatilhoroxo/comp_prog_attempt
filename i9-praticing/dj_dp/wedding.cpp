//uva 11450 - Wedding shopping
//
#include <bits/stdc++.h>
using namespace std;

int infinito = 15 << 27;

int rectop(int money, int g, int& m, int& c, 
    vector<vector<int>>& price,
    vector<vector<int>>& table)
{
    if(money<0) return ((-1)*infinito);
    if(g==c) return m - money;
    if(table[money][g] != -1) return table[money][g];
    int ans = -1; 
    for(int model = 0; model < price[g].size(); model++){
        ans = max(ans, rectop(money - price[g][model], g+1, m, c, price, table));
    }
    table[money][g] = ans;
    return ans;
}

//logica incompleta
int solve_bot(int m, vector<vector<int>> price){
    vector<vector<bool>> reacheble(25, vector<bool>(210, false));
    for(int i=0; i< price[0].size(); i++){
        if(m - price[0][i] >= 0)
            reacheble[0][m - price[0][i]] = true;
    }
    
    int money=0, c = price.size();
    for(int g = 0; g<c; g++){
        for(money=0; money < m; money++){
            for(int k=0; k<price[g].size(); k++){
                reacheble[g][abs(money-price[g][k])] = true;
            }
        }
    }
    for(money=0; money <= m && !reacheble[c-1][money]; money++);
    return money;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>> n;
    while(n--){
        int m,c;
        cin >> m >> c;
        vector<vector<int>> vt(c);
        int k=0;
        for(int i=0; i<c; i++){
            cin >> k;
            vt[i].resize(k);
            for(auto &j: vt[i]) cin >> j;
        }
        vector<vector<int>> table(210, vector<int>(25, -1));
        int ans = rectop(m, 0, m, c, vt, table);
        if(ans < 0) cout << "no solution\n";
        else cout << ans << '\n';
        /*
        int ansbot = solve_bot(m, vt);
        if(ansbot == m +1) cout << "no solution\n";
        else cout << m-ansbot << '\n';
        */
        
    }

    return 0;
}