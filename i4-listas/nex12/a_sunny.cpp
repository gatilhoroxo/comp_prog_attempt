//sunny mountains
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define lld long double
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
struct vet { 
    long double x, y; 
    vet(long double _x, long double _y) : x(_x), y(_y) {}
};


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n; cin >> n;
    lld ans=0;
    vec(point) vt(n);
    for(auto&v: vt) cin >> v.x >> v.y;

    /*
    ponto da interseção de duas retas
    distancia desse ponto até o topo da montanha
    */

    printf("%ld\n",ans);

    }

    return 0;
}