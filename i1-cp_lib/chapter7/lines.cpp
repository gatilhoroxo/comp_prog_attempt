#include "../cp_lib.hpp"
#include "point.cpp"

#define EPS 1e-9
#define PI acos(-1.0)

// Equação ax + by + c = 0 
struct line { double a, b, c; }; 

// Computar coeficientes da linha dados dois pontos 
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // Linha vertical
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

// Verificar se linhas são paralelas 
bool areParallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// Verificar se linhas são iguais
bool areSame(line l1, line l2) {
    return areParallel(l1,l2) && (fabs(l1.c - l2.c) < EPS);
}

// Verificar interseção e encontrar o ponto 
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else                  p.y = -(l2.a * p.x + l2.c);
    return true;
}

//---==---==---==---==---==---==---==---==---==---==---==---

// Vetores e utilitários 
struct vet { 
    double x, y; 
    vet(double _x, double _y) : x(_x), y(_y) {}
};

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

//---==---==---==---==---==---==---==---==---==---==---==---

// Teste CCW (Counter Clockwise) 
// Retorna true se o ponto r está à esquerda da linha pq
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

// returns true if point r is on th same line as the line pq
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p,q), toVec(p,r))) < EPS;
}

// Distância de ponto p à linha definida por a e b 
double distToLine(point p, point a, point b, point &c) {
    vet ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    return dist(p, c);
}

double distToLineSegment(point p, point a, point b, point &c) {
    vet ap = toVec(a, p), ab = toVec(a,b);
    double u = dot(ap,ab) / norm_sq(ab);
    if(u < 0.0) {
        c = point(a.x, a.y);
        return dist(p,a);
    }
    if(u > 1.0){
        c = point(b.x, b.y);
        return dist(p,b);
    }
    return distToLine(p,a,b,c);
}

// Ponto dentro do polígono (Winding Number) 
// Retorna true se o ponto pt está dentro do polígono P
double angle(point a, point o, point b) { // Ângulo aob em radianos 
    vet oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

