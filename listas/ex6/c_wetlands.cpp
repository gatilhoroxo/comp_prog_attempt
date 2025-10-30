//wetlands of florida
//tle
#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vpi = vector<pair<pair<int,int>,int>>;
using vvt = vector<vpi>;

struct FloodFill {
    int R, C;
    vector<string> grid;
    vi dr, dc;
    vvt pares;

    FloodFill(int R_, int C_, const vector<string>& grid_)
        : R(R_), C(C_), grid(grid_) {
            dr.resize(8); dc.resize(8);
            dr = {1, 1, 0,-1,-1,-1, 0, 1};
            dc = {0, 1, 1, 1, 0,-1,-1,-1};
        }

    void reset(vector<string>& grid_) { grid = grid_; }
    
    int call_fill(int r, int c){
        vpi par;
        int res = check_par(r, c);
        res = (res == -1 ? fill(par, r, c, 'W', '.') : res);
        for(auto&i:par){ i.second = res; }
        pares.push_back(par);
        return res;
    }

    int fill(vpi& par, int r, int c, char c1, char c2){
        if(r<0 || r>= R || c < 0 || c>= C) return 0;
        if(grid[r][c] != c1) return 0;
        int ans = 1;
        grid[r][c] = c2;
        par.push_back({{r,c},0});
        for(int d=0; d<8; d++)
            ans += fill(par, r+dr[d], c+dc[d], c1, c2);
        return ans;
    }

    int check_par(int r, int c){
        if(pares.empty()) return -1;
        for(auto&i: pares){
            for(auto&j:i){
                if(make_pair(r,c)==j.first){
                    return j.second;
                }
            }
        }
        //cout << "ta aqui: " << endl;
        return -1;
    }

};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while(t--){
        // processamento do input
        string ms = "";
        int cnt=0;
        vector<string> lake;
        for(;;){
            cin >> ms;
            if(ms.size() == 1) break;
            lake.push_back(ms);
            cnt++;
        }
        int n = cnt;
        int m = lake[0].size();

        FloodFill ff(n, m, lake);
        int w=atoi(&ms[0]), l;
        cin >> l;
        cout << ff.call_fill(w,l) << '\n';
        for(;(cin >> w >> l);){
            //ff.reset(lake);
            cout << ff.call_fill(w-1,l-1) << '\n';
        }
        //fim do processamento do input

        //for(auto&i:lake) { cout << i << '\n';}

        
    }
}
