#include <bits/stdc++.h>
using namespace std;

int main(){
    // p = [4, 5, 3, 1, 2] (1-indexed)
    // d = [4, 5, 1, 3, 2] (1-indexed)
    // inv: inv[1]=4, inv[2]=5, inv[3]=3, inv[4]=1, inv[5]=2
    
    // Processando ao contrário:
    // i=4: d[4]=2, p[2]=5, val=5
    //      usado[2]=true
    //      tenta unir 2 com 5 (usado[5]? não) -> não une
    //      tenta unir 2 com inv[2]=5 (usado[5]? não) -> não une
    //      saved=0, ans[4] = 5 - 0 = 5 ✓
    
    // i=3: d[3]=3, p[3]=3, val=3
    //      usado[3]=true
    //      tenta unir 3 com 3 -> NÃO (pos==val)
    //      tenta unir 3 com inv[3]=3 -> NÃO (pos==inv[pos])
    //      saved=0, ans[3] = 4 - 0 = 4 ✗ (esperado 5)
    
    cout << "O problema é que quando p[i]==i, não estamos economizando mas deveríamos!\n";
    cout << "Na verdade, quando p[i]==i, esse elemento JÁ está correto, então economiza 1 op.\n";
    
    return 0;
}
