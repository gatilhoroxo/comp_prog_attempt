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
        float fuel=30;
        float regra=0;
        int leak=0;
        int distance, antigo; string type;
        cin >> distance >> type;
        do{
            if(type == "Fuel"){
                cin >> type >> consume;
            } else if (type == "Gas") {
                cin >> type;
                fuel=30;
            } else if(type == "Leak"){
                leak++;
            } else if(type == "Mechanic"){
                leak=0;
            } else if(type == "Goal"){
                regra+=((consume + leak)*distance/100);
                fuel-=(regra);
                break;
            }
            //processar o evento
            if(distance!=0) regra+=((consume)*distance/100);
            if(leak != 0) regra+=(distance*leak);
            fuel-=(regra);
            cin >> distance >> type;
        }while(type!="Goal");

        printf("%0.3f\n", regra);

    }

    return 0;
}

int albe_main(){
    vector<tuple<int,string,int>> events;
    float rate, licks=0, sum=0, max=0, start=0;
    while(true){
        string event;
        //decodifica entrada 
        int loc_atual;
        string event_type;
        int buff;
        int distance; //onde ta agr - inicio
        //muda inicio 
        if(distance != 0){
            sum+=((rate*distance)/100);
        }
        if(licks != 0) {
            sum += licks*distance;
        }
        
        if(event_type == "Fuel"){
            if(loc_atual == 0 && buff == 0){
                break;
            }
            rate = buff;
        } else if (event_type == "Gas"){
            if(sum>max){ max = sum; }
            printf("%.3f\n",max);
            licks=0,sum=0,start = 0;
        }
    }
}