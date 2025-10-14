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
        //caso 1
        int inicio, consume=0; string start; 
        cin>>inicio>>start>>start>>consume; 
        if(inicio==0 && consume==0){ break; }
        vector<pair<string, int>> vt(50);
        float soma=0, max=0;
        int leak=0, loc=0, loc_atual=0;
        int distance=0; 
        string type;
        while(true){
            cin >> loc >> type;

            distance = abs(loc - loc_atual);
            loc_atual= loc;
            if(distance!=0) soma+=((consume)*distance/100);
            if(leak != 0) soma+=(distance*leak);

            if(type == "Fuel"){
                cin >> type >> consume;
            } else if (type == "Gas") {
                cin >> type;
                if(soma>max) { max = soma; }
                soma = 0;
            } else if(type == "Leak"){
                leak++;
            } else if(type == "Mechanic"){
                leak=0;
            } else if(type == "Goal"){
                if(soma > max) max = soma;
                break;
            }
        } 

        printf("%0.3f\n", soma);

    }

    return 0;
}
