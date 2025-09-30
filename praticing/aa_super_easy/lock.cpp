//UVa 10550 - Combination Lock
//eh só criar uma fórmula, e eu não sei fazer isso
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n[4];
    //1) -2 full turns; 2) stop till the 1st num; 3) +1 full turn; 4) continue until the 2nd num; 5) + turn till the 3rd num; 6) pull and open;
    bool zeros = false;
    while(!zeros){
        cin >> n[0] >> n[1] >> n[2] >> n[3];
        zeros = !n[0] && !n[1] && !n[2] && !n[3];

        //degrees
        //0 == 0 ou 360
        //20 == 180
        //10 == x(90)
        //1 == 9
        int degree = 9;
        int dif = (n[1] - n[0]); 
        //dif = dif < 0 ? 40 + dif : dif;
        int dife = (n[2] - n[1]);
        dife = dife < 0 ? 40 + dife : dife;
        int defer = (n[3] - n[2]);
        //defer = defer < 0 ? 40 + defer : defer;
        int ans = 3*360 + dif*(degree) + dife*(degree) + defer*degree;

        if (!zeros) cout << ans << '\n';
    }

    return 0;
}