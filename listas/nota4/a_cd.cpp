//CD
//i made this
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ivi = pair<int, vector<int>>; 
#define sum first
#define musicas second

ivi comp(ivi& a, ivi& b, int& d){
    if(a.sum <= d && b.sum <= d){
        return (a.sum > b.sum ? a : b);
    } else if (a.sum <= d) return a;
    else return b;
}

ivi rec(vi& vt, int idx, int& n, ivi cur){
    if(idx == vt.size()) return cur;
    if(cur.sum>n) { return cur; } 
    else if(cur.sum==n) return cur;
    //sem a musica
    ivi m1 = rec(vt, idx+1, n, cur);
    //com a musica
    ivi cur_with = cur;
    cur_with.sum+=vt[idx];
    cur_with.musicas.push_back(vt[idx]);
    ivi m2 = rec(vt, idx+1, n, cur_with);
    return comp(m1, m2, n);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; 
    while(cin >> n){
        int musics; cin >> musics;
        vector<int> vt(musics);
        for(auto & i: vt) cin >> i;
        // sort(vt.begin(), vt.end());
        ivi ms({0, vector<int>()});
        ivi m = rec(vt, 0, n, ms);

        for(auto &i: m.musicas){ cout << i << ' '; }
        cout << "sum:" << m.sum << '\n';
    }

    return 0;
}