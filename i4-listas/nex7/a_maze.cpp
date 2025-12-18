//basic wall maze
#include <bits/stdc++.h>
using namespace std;

#define UNVISITED false
#define VISITED true
//================
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

    bool operator==(const par& other){
        return i == other.i && j == other.j;
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
    vector<vector<bool>> mark;
    vector<vector<par>> parent;
    string path;
    void setMark(par v, bool val){
        mark[v.i][v.j] = val;
    } 
    bool getMark(par v){
        return mark[v.i][v.j];
    }

    void build_maze_with_walls(vector<points>& w){
        // blockedH[y][x] = true if horizontal wall at y between x and x+1
        // blockedV[x][y] = true if vertical wall at x between y and y+1
        vector<vector<int>> blockedH(6, vector<int>(6, 0));
        vector<vector<int>> blockedV(6, vector<int>(6, 0));
        
        for(auto& wall : w){
            int x1 = wall.a.j, y1 = wall.a.i;
            int x2 = wall.b.j, y2 = wall.b.i;
            
            if(y1 == y2){
                // horizontal wall at y = y1, from x = min(x1,x2) to max(x1,x2)-1
                int y = y1;
                int xmin = min(x1, x2);
                int xmax = max(x1, x2);
                for(int x = xmin; x < xmax; x++){
                    if(x >= 0 && x < 6 && y >= 0 && y < 6){
                        blockedH[y][x] = true;
                    }
                }
            } else if(x1 == x2){
                // vertical wall at x = x1, from y = min(y1,y2) to max(y1,y2)-1
                int x = x1;
                int ymin = min(y1, y2);
                int ymax = max(y1, y2);
                for(int y = ymin; y < ymax; y++){
                    if(x >= 0 && x < 6 && y >= 0 && y < 6){
                        blockedV[x][y] = true;
                    }
                }
            }
        }
        
        // build adjacency list considering walls
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                // down (S)
                if(i+1 < n && !blockedH[i][j]) vt[i][j].push_back(par(i+1,j));
                // up (N)
                if(i-1 >= 0 && !blockedH[i-1][j]) vt[i][j].push_back(par(i-1,j));
                // right (E)
                if(j+1 < n && !blockedV[j][i]) vt[i][j].push_back(par(i,j+1));
                // left (W)
                if(j-1 >= 0 && !blockedV[j-1][i]) vt[i][j].push_back(par(i,j-1));
            }
        }
    }
    
public:
    maze(){
        n = 6;
        vt.assign(n,vvp(n));
        parent.assign(n,vector<par>(n,par(-1,-1)));
    }
    maze(par&s, par&e, vector<points>&w){
        maze();
        start = s;
        end = e;
        build_maze_with_walls(w);
    }
    
    //melhor menor caminho com bfs pois as arestas nao tem pesos
    //ver se ta certo, fiz de cabeça
    void path_bfs(){
        queue<par> fila;
        fila.push(start);
        mark.assign(n, vector<bool>(n, UNVISITED));
        parent.assign(n, vector<par>(n, par(-1,-1)));
        setMark(start, VISITED);

        while(!fila.empty()){
            par u = fila.front(); fila.pop();
            
            if(u == end) break;
            
            for(auto&v:vt[u.i][u.j]){
                if(getMark(v) == UNVISITED){
                    setMark(v, VISITED);
                    parent[v.i][v.j] = u;
                    fila.push(v);
                }
            }
        }
    }
    
    //TO-DO ver como guardar o melhor menor caminho feito
    void call(){
        //ver como chega no final
        if(parent[end.i][end.j].i == -1) {
            // no path found, but problem guarantees there is one
            return;
        }
        
        vector<par> path;
        par current = end;
        while(!(current == start)) {
            path.push_back(current);
            current = parent[current.i][current.j];
        }
        path.push_back(start);
        reverse(path.begin(), path.end());
        
        // convert path to directions
        string directions = "";
        for(size_t i = 1; i < path.size(); i++) {
            par prev = path[i-1];
            par curr = path[i];
            
            if(curr.i == prev.i + 1) directions += "S"; // down (row increases)
            else if(curr.i == prev.i - 1) directions += "N"; // up (row decreases)
            else if(curr.j == prev.j + 1) directions += "E"; // right (col increases)
            else if(curr.j == prev.j - 1) directions += "W"; // left (col decreases)
        }
        
        cout << directions << endl;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b;
    while(cin >> a >> b)
    {
        if(a == 0 && b == 0) break;
        par start(a-1,b-1); // converter para 0-based

        cin >> a >> b;
        par end(a-1,b-1); // converter para 0-based
        
        vector<points> walls(3);
        for(int i=0; i<3; i++){
            cin >> walls[i].a.j >> walls[i].a.i;
            cin >> walls[i].b.j >> walls[i].b.i;
        }
        
        maze table(start, end, walls);
        table.path_bfs();
        table.call();
    }

    return 0;
}