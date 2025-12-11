//hurricane danger
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define ll long long
#define INF 1'000'000
#define EPS 1e-9
#define PI acos(-1.0)

struct point { 
    long double x, y;
    point() { x = y = 0.0; }
    point(long double _x, long double _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

long double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
struct vet { 
    long double x, y; 
    vet(long double _x, long double _y) : x(_x), y(_y) {}
};

vet toVec(point a, point b) { 
    return vet(b.x - a.x, b.y - a.y); 
}
vet scale(vet v, long double s) { 
    return vet(v.x * s, v.y * s); 
}
point translate(point p, vet v) { 
    return point(p.x + v.x, p.y + v.y); 
}
long double dot(vet a, vet b) { 
    return (a.x * b.x + a.y * b.y); 
}
long double norm_sq(vet v) { 
    return v.x * v.x + v.y * v.y; 
}
long double cross(vet a, vet b) { 
    return a.x * b.y - a.y * b.x; 
}

// Distância de ponto p à linha definida por a e b 
long double distToLine(point p, point a, point b, point &c) {
    vet ap = toVec(a, p), ab = toVec(a, b);
    long double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}


#define pii pair<string,point>

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    point a,b,c;
    cin >> a.x >> a.y >> b.x >> b.y;

    int n; cin >> n;
    vec(pii) vt(n);
    vec(long double) dist(n,0);
    long double menor=INF;
    for(int i=0; i<n; i++){
        cin >> vt[i].first;
        cin >> vt[i].second.x >> vt[i].second.y;
        //distancia até a reta
        dist[i] = distToLine(vt[i].second,a,b,c);
        menor = min(menor, dist[i]);
    }   

    /*
    para resolver esse problema é preciso: 
    1. extrair a reta dos pontos que foram dados (o que o furacão vai passar). 
    2. calcular a distância de cada cidade para a reta. 
    3. ver qual tem o maior nível de perigo. 
    */

    //for(auto val: dist) cout << val << ' '; cout << '\n';

    for(int i=0; i<n; i++){
        if(fabs(dist[i] - menor) < EPS){
            cout << vt[i].first << ' ';
        }
    }
    cout << "\n";

    }

    return 0;
}