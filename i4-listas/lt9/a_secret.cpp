//secret words 
#include <bits/stdc++.h>
using namespace std;
#define vec(n) vector<n>
#define ll long long

const ll MOD = 1e9 + 7;

bool func(string& texto, int start, string& palavra) {
    if (start + palavra.length() > texto.length()) return false;
    for (int i = 0; i < palavra.length(); i++) {
        if (texto[start + i] != '?' && texto[start + i] != palavra[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vec(string) palavras(n);
    for (auto&s:palavras) { cin >> s; }

    string texto; cin >> texto;
    int tam = texto.length();

    vec(ll) dp(tam + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < tam; i++) {
        if (dp[i] == 0) continue; 
        for (string& s : palavras) {
            if (func(texto, i, s)) {
                int next_pos = i + s.length();
                dp[next_pos] = (dp[next_pos] + dp[i]) % MOD;
            }
        }
    }
    cout << dp[tam] << "\n";

    return 0;
}