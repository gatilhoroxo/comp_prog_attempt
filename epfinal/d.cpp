//chessboard and queens
//8 rainhas
//lugares reservados
#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define n 8

//guarda a posição das rainhas
vector<bool> row(n,false), 
             ld(n,false), 
             rd(n,false); 
vector<string> board(n,"");
ll ans=0;

void backtrack(int c){
    if(c == n) { ans++; return; }
    for(int r=0; r<n; r++){
        if( board[r][c] != '*' && 
            !row[r] &&
            !ld[r-c + n-1] && 
            !rd[r+c])
        {
            row[r] = ld[r-c+n-1] = rd[r+c] = true;
            backtrack(c+1);
            row[r] = ld[r-c+n-1] = rd[r+c] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(auto&s:board){ cin >> s; }

    ans=0;
    backtrack(0);

    //o numero de maneiras de colocar as rainhas
    cout << ans << '\n';

    return 0;
}
