//time limit
#include <bits/stdc++.h>
using namespace std;

#define vec(n) vector<n>
#define lld long double
#define EPS 1e-9
#define PI acos(-1.0)
#define ninety PI/2

struct point { 
    lld x, y;
    point() { x = y = 0.0; }
    point(lld _x, lld _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};
struct vet { 
    lld x, y; 
    vet(lld _x, lld _y) : x(_x), y(_y) {}
};
// Equação ax + by + c = 0 
struct line { double a, b, c; }; 

// Distância Euclidiana 
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

vet toVec(point a, point b) { 
    return vet(b.x - a.x, b.y - a.y); 
}
vet scale(vet v, double s) { 
    return vet(v.x * s, v.y * s); 
}
point translate(point p, vet v) { 
    return point(p.x + v.x, p.y + v.y); 
}
double dot(vet a, vet b) { 
    return (a.x * b.x + a.y * b.y); 
}
double norm_sq(vet v) { 
    return v.x * v.x + v.y * v.y; 
}
double cross(vet a, vet b) { 
    return a.x * b.y - a.y * b.x; 
}

//Ângulo aob em radianos
lld angle(point a, point o, point b) {  
    vet oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

struct jota {
    vec(point) vt;
};
int solve(jota& sv);

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; while(t--)
    {

    int n; cin >> n;
    vec(point) vt(n);
    for(auto&i: vt) { cin >> i.x >> i.y; }
    jota sv;
    sv.vt = vt;
    int ans=solve(sv);
    cout << ans << '\n';

    }

    return 0;
}

int solve(jota& sv){
    vec(point)& vt = sv.vt;
    int n = vt.size();
    
    map<lld, int> cnt0, cnt1;
    
    for(auto& p : vt) {
        if(fabs(p.y) < EPS) {
            cnt0[p.x]++;
        } else {
            cnt1[p.x]++;
        }
    }
    
    long long ans = 0;
    
    // Para cada ponto como vértice do ângulo reto
    for(int i = 0; i < n; i++) {
        point mid = vt[i];
        
        // Como y ∈ {0, 1}, vetores podem ser categorizados
        int horizontal = 0; // dy=0
        int vertical = 0;   // dx=0
        map<pair<lld, lld>, int> diagonal;
        
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            
            lld dx = vt[j].x - mid.x;
            lld dy = vt[j].y - mid.y;
            
            if(fabs(dy) < EPS) {
                horizontal++;
            } else if(fabs(dx) < EPS) {
                vertical++;
            } else {
                diagonal[{dx, dy}]++;
            }
        }
        
        // Horizontal ⊥ Vertical
        ans += (long long)horizontal * vertical;
        
        // Diagonal ⊥ Diagonal: produto escalar = 0
        for(auto& [v1, cnt1] : diagonal) {
            for(auto& [v2, cnt2] : diagonal) {
                if(v1 < v2) {
                    lld dx1 = v1.first, dy1 = v1.second;
                    lld dx2 = v2.first, dy2 = v2.second;
                    
                    if(fabs(dx1*dx2 + dy1*dy2) < EPS) {
                        ans += (long long)cnt1 * cnt2;
                    }
                }
            }
        }
    }
    
    return ans;
}