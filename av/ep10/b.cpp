//basic code
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define lld long double
#define EPS 1e-9
#define PI acos(-1.0)
#define ninety PI/2

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
// Equação ax + by + c = 0 
struct line { lld a, b, c; }; 

vet toVec(point a, point b) { 
    return vet(b.x - a.x, b.y - a.y); 
}
lld cross(vet a, vet b) { 
    return a.x * b.y - a.y * b.x; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    point ra,rb,c;
    cin >> ra.x >> ra.y;
    cin >> rb.x >> rb.y;
    cin >> c.x >> c.y;

    vet ab = toVec(ra, rb);
    vet ac = toVec(ra, c);
    lld crossProduct = cross(ab, ac);
    
    if(fabs(crossProduct) < EPS){
        cout << "TOUCH\n";
    } else if(crossProduct > 0){
        cout << "LEFT\n";
    } else {
        cout << "RIGHT\n";
    }

    }

    return 0;
}