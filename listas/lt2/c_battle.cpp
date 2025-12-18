//lemmings battle!
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    while(n--){
        int battles, sgreen, sblue;
        cin >> battles >> sgreen >> sblue;
        
        vector<int> gteam(sgreen);
        for(int i=0; i<sgreen; i++){ cin >> gteam[i]; }
        priority_queue<int> pqG(gteam.begin(), gteam.end());

        vector<int> bteam(sblue);
        for(int i=0; i<sblue; i++){ cin >> bteam[i]; }
        priority_queue<int> pqB(bteam.begin(), bteam.end());
        
        gteam.clear(); bteam.clear();
        string outGdead="blue wins\n", outBdead="green wins\n", outTdead="green and blue died\n";
        
        while(!pqB.empty() && !pqG.empty()){
            bool notvazios=true;
            for(int i=0; i<battles && notvazios; i++){
                int green_power = pqG.top();
                int blue_power = pqB.top();
                pqG.pop(); pqB.pop();

                int res = 0;
                if (blue_power < green_power){
                    res = (green_power - blue_power);
                    gteam.push_back(res); 
                } else if(green_power < blue_power){
                    res = (blue_power - green_power);
                    bteam.push_back(res);
                } 
                notvazios = !pqG.empty() && !pqB.empty();
                //cout << blue_power <<  " - " << blue_power << " = " << res << endl;
            }
            if(gteam.size() != 0){
                for(auto gm : gteam){
                    pqG.push(gm);
                }
                gteam.clear();
            }
            if(bteam.size() != 0){
                for(auto bm : bteam){
                    pqB.push(bm);
                }
                bteam.clear();
            }
        }

        if(pqB.empty() && pqG.empty()) {
            cout << outTdead;
        } else if(pqB.empty()){
            cout << outBdead;
            while(!pqG.empty()){
                cout << pqG.top() << '\n';
                pqG.pop();
            }
        } else {
            cout << outGdead;
            while(!pqB.empty()){
                cout << pqB.top() << '\n';
                pqB.pop();
            }
        }
        if(n!=0) cout << '\n';

    }

    return 0;
}