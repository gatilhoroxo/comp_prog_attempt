//Disappearing Permutation
#include <bits/stdc++.h>
using namespace std;

#define vi vector<int> 

class UnionFind {
private: 
    vi p, rank;
    
public:
    UnionFind(int N) {
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) {
        return (p[i] == i) ? i : (p[i] = findSet(p[i])); 
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if(!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y]) {
                p[y] = x;
            } else {
                p[x] = y;
                if(rank[x] == rank[y]) {
                    rank[y]++;
                }
            }
        }
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vi p(n+1); // permutação (1-indexada)
        vi inv(n+1); // inversa: inv[val] = pos onde p[pos] = val
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
            inv[p[i]] = i;
        }
        
        vi d(n); // sequência de remoções (0-indexada)
        for(int i = 0; i < n; i++) {
            cin >> d[i];
        }
        
        // DSU para rastrear componentes
        UnionFind dsu(n+1);
        
        // Marca quais índices foram recolocados
        vector<bool> usado(n+1, false);
        
        // Vetor para armazenar respostas (processar ao contrário)
        vi ans(n);
        
        // Começamos com resposta = n (tudo precisa ser consertado)
        int resposta = n;
        
        // Processa de trás pra frente (recolocando elementos)
        for(int i = n-1; i >= 0; i--) {
            int pos = d[i]; // posição que será recolocada
            int val = p[pos]; // valor que estava nessa posição
            
            usado[pos] = true;
            resposta--; // restauramos um elemento, diminui a resposta
            
            // Tenta unir pos com val (onde val deveria estar)
            if(usado[val] && !dsu.isSameSet(pos, val)) {
                dsu.unionSet(pos, val);
                resposta--; // união economiza mais uma operação
            }
            
            // Tenta unir pos com inv[pos] (onde está o valor que deveria estar em pos)
            if(usado[inv[pos]] && !dsu.isSameSet(pos, inv[pos])) {
                dsu.unionSet(pos, inv[pos]);
                resposta--;
            }
            
            ans[i] = resposta;
        }
        
        // Imprime as respostas na ordem correta
        for(int i = 0; i < n; i++) {
            cout << ans[i];
            if(i < n-1) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}