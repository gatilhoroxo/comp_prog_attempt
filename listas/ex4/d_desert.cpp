//UVa 11935 - Through the Desert 
//não entendi bem o problema inicialmente
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //Fuel : n L/100km
    //Leak : perda de 1L por km
    //increase survival
        //Gas station : fill up the tank
        //Mechanic : fix all the leaks
    //Goal : reached to the end
    while(true){
        int inicio, fuel_consume=0; string start; 
        cin>>inicio>>start>>start>>fuel_consume; 
        if(inicio==0 && fuel_consume==0){ break; }
        vector<pair<string, int>> vt(50);
        float max_fuel=0, fuel_used=0;
        int leak=0, last_loc=0, loc_atual=0;
        int dist=0; 
        string type_event;
        while(true){
            cin >> loc_atual >> type_event;

            dist = abs(last_loc - loc_atual);
            last_loc = loc_atual;
            if(dist!=0) fuel_used+=((fuel_consume)*dist/100) + (dist*leak);

            if(type_event == "Fuel"){
                cin >> type_event >> fuel_consume;
            } else if(type_event == "Leak"){
                leak++;
            } else if(type_event == "Mechanic"){
                leak=0;
            } else if (type_event == "Gas") {
                cin >> type_event;
                max_fuel = max(fuel_used, max_fuel); 
                fuel_used = 0;
            } else if(type_event == "Goal"){
                max_fuel = max(fuel_used, max_fuel);
                break;
            }
        } 

        printf("%0.3f\n", max_fuel);

    }

    return 0;
}
