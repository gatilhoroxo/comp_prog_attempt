//Taxi
//foi essa coisa
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >>t; while(t--)
    {

    int n, ans=0; 
    cin >> n;
    map<int,int> grups;
    for(int i=0; i<n; i++) { 
        int temp; cin >> temp; 
        grups[temp]++;
    }

    //primeiros carros
    ans+=grups[4];
    //segundos carros
    ans+=grups[3];
    grups[1] -= (grups[1]>grups[3] ? grups[3] : grups[1]);
    //terceiros carros
    ans+=grups[2]/2;
    if(grups[2]%2==1) {ans++; grups[1]-=(grups[1]>2 ? 2:grups[1]);}
    //quatros carros
    ans+=(grups[1]>0 ? ((grups[1]+3)/4) : 0);

    cout << ans << '\n';

    }


    return 0;
}

/*
    {
    int n, ans=0, aux3=0, aux2=0; 
    cin >> n;
    vector<int> grups(n);
    for(auto&i:grups) { cin >> i; }
    sort(grups.begin(), grups.end(), greater<int>());
    for(int i=0; i<n; i++){
        if(grups[i] == 4) ans++;
        else if(grups[i] == 3) {
            aux3++; 
            ans++;
        } else if(grups[i] == 2) {
            aux2++;
            ans+=(aux2%2 ? 0 : 1);
        } else {
            aux3--;
        }
    }
    if(aux2%2==1) {ans++; aux3+=2;}
    if(aux3<0) ans+=(ceil(aux3*(-1) / 4));

    cout << ans << '\n';

    }
*/