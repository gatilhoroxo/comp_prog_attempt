//basic wall maze
#include <bits/stdc++.h>
using namespace std;

#define UNVISITED false
#define VISITED true
using vi = vector<int>;
using vvi = vector<vi>;

struct par{
    int i;
    int j;
    par(){
        i=j=0; 
    }
    par(int a, int b){
        i = a;
        j = b;
    }
};
struct points{
    par a, b;
};

using vp = vector<par>;
using vvp = vector<vp>;
class maze{
private:
    int n;
    par start, end;
    vector<vvp> vt;
    vector<points> walls;
    vector<vector<bool>> mark;
    void setMark(par v, bool val){
        mark[v.i][v.j] = val;
    } 
    bool getMark(par v){
        return mark[v.i][v.j];
    }
public:
    maze(){
        n = 6;
        vt.assign(6,vvp(6));
    }
    maze(vector<points>& w){
        maze();
        store_walls(w);
    }
    maze(par&s, par&e, vector<points>&w){
        maze(w);
        start = s;
        end = e;
    }
    void build_maze(){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i+1<n) vt[i][j].push_back(par(i+1,j));
                if(i-1>=0) vt[i][j].push_back(par(i-1,j)); 
                if(j+1<n) vt[i][j].push_back(par(i,j+1));
                if(j-1>=0) vt[i][j].push_back(par(i,j-1));
            }
        }
    }
    void store_walls(vector<points>& w){
        walls = w;
    }
    
    //melhor menor caminho com bfs pois as arestas nao tem pesos
    //ver se ta certo, fiz de cabeça
    void path_bfs(){
        queue<par> fila;
        fila.push(start);
        mark.assign(n, vector<bool>(n, UNVISITED));
        while(!fila.empty()){
            par u = fila.front(); fila.pop();
            for(auto&v:vt[u.i][u.j]){
                if(getMark(v) == UNVISITED){
                    setMark(v, VISITED);
                    fila.push(v);
                }
            }
        }
    }
    
    //TO-DO ver como guardar o melhor menor caminho feito
    void call(){
        //ver como chega no final
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        par start(a,b);

        cin >> a >> b;
        par end(a,b);
        vector<points> walls;
        for(auto&w:walls){
            cin >> w.a.i >> w.a.j;
            cin >> w.b.i >> w.b.j;
        }
        maze table(start, end, walls);
        

    }

    return 0;
}