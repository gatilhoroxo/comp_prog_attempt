//concert tickets
#include <bits/stdc++.h>
using namespace std;
#define infinito (15 << 27)

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n_tic, m_cli; 
    cin >> n_tic >> m_cli;
    multiset<int> tickets;
    for(int i=0; i<n_tic; i++){
        int tic;
        cin >> tic;
        tickets.insert(tic);
    }
    
    int clients;
    for(int i=0; i<m_cli; i++){
        cin >> clients;
        auto it = tickets.upper_bound(clients);
        //cout << *it << '\n';
        if(it == tickets.begin()){
            cout << -1 << '\n';
        }
        else {
            cout << *(--it) << '\n';
            tickets.erase(it);
        }  
    }

    return 0;
}