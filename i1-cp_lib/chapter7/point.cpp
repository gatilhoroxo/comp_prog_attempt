#include "../cp_lib.hpp"
#include <cmath>

#define EPS 1e-9
#define PI acos(-1.0)

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

// Distância Euclidiana 
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// Rotacionar ponto p por theta graus no sentido anti-horário em torno da origem (0,0) [cite: 1576]
point rotate(point p, double theta) {
    double rad = theta * (PI / 180.0);
    return point(p.x * cos(rad) - p.y * sin(rad),
                 p.x * sin(rad) + p.y * cos(rad));
}