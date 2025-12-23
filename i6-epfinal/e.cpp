//point location test
#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

#define lld long double

struct point { 
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}

    // Sobrecarga para ordenação
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    
    // Sobrecarga para igualdade
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

struct vet { 
    double x, y; 
    vet(double _x, double _y) : x(_x), y(_y) {}
};

vet toVec(point a, point b) { 
    return vet(b.x - a.x, b.y - a.y); 
}
double cross(vet a, vet b) { 
    return a.x * b.y - a.y * b.x; 
}

bool collinear(vet a, vet b){
    return fabs(cross(a, b)) < EPS;
}

//HEREEE
bool esquerda(vet a, vet b){
    return cross(a,b) > 0;
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

    if(collinear(ab,ac)){
        cout << "TOUCH\n";
    } else if(esquerda(ab, ac)){
        cout << "LEFT\n";
    } else {
        cout << "RIGHT\n";
    }


    }

    return 0;
}