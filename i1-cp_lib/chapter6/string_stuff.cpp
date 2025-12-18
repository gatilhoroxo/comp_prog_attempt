#include "../cp_lib.hpp"


vec(ll) computaLPS(string padrao){
    ll tam = padrao.length();
    vec(ll) lps(tam, 0);
    ll len = 0;
    ll i=1;

    while(i<tam) {
        if(padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len -1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

ll contaOcorrencias(string texto, string padrao){
    ll n = texto.length();
    ll m = padrao.length();

    if(m>n) return 0;

    vec(ll) lps = computaLPS(padrao);
    ll cnt = 0;
    ll it = 0;
    ll jp = 0;

    while(it < n) {
        if(texto[it] == padrao[jp]){
            it++;
            jp++;
        }

        if(jp==m){
            cnt++;
            jp = lps[jp-1];
        } else if(it < n && texto[it] != padrao[jp]){
            if(jp != 0) {
                jp = lps[jp-1];
            } else {
                it++;
            }
        }
    }
    return cnt;
}
