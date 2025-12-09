//convex hull
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define ll long long
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

long double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
long double cross(vet a, vet b) { 
    return a.x * b.y - a.y * b.x; 
}

vet toVec(point a, point b) { 
    return vet(b.x - a.x, b.y - a.y); 
}
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

//diferente do que está em chapter7/lines.cpp
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > -EPS;
}


point pivot(0,0);
//angle-sorting function
bool angleCmp(point a, point b) {
    //spacial case
    if(collinear(pivot, a, b))
        return dist(pivot,a) < dist(pivot,b);
    long double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    long double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y,d1x) - atan2(d2y,d2x)) < 0; //compare two angles
}


vector<point> CH(vector<point> P){
    ll i,j,n = (ll)P.size();
    //special case, the CH is P itself
    if(n <= 3) {
        if(!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }

    ll P0 = 0;
    for(i=1; i<n; i++){
        if(P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    }

    //swap
    point temp = P[0]; 
    P[0] = P[P0];
    P[P0] = temp;

    pivot = P[0];
    sort(++P.begin(),P.end(),angleCmp);

    vector<point> S;
    S.push_back(P[0]);
    S.push_back(P[1]);
    
    i=2;
    while(i<n){
        j = (int)S.size() -1;
        if(ccw(S[j-1],S[j],P[i])) 
            S.push_back(P[i++]);
        else S.pop_back();
    }
    S.push_back(P[0]); // fecha o hull
    return S;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //int t; cin >> t; while(t--)
    {

    int n; 
    cin >> n;
    vec(point) vt(n);
    for(auto& val: vt){
        cin >> val.x >> val.y;
    }

    vec(point) ans = CH(vt);

    cout << ans.size()-1<< '\n';
    for(int i=0; i<(int)ans.size()-1; i++){
        cout << (ll)ans[i].x << ' ' << (ll)ans[i].y << '\n';
    }


    }

    return 0;
}