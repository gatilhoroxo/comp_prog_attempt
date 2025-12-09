#include "../cp_lib.hpp"
#include "lines.cpp"



// Perímetro do polígono [cite: 1198]
double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++)
        result += dist(P[i], P[i+1]);
    return result;
}

// Área do polígono (Shoelace formula) [cite: 1220]
double area(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        result += (P[i].x * P[i+1].y - P[i+1].x * P[i].y);
    }
    return fabs(result) / 2.0;
}

// Verificar se é convexo [cite: 1227]
bool isConvex(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false;
    bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz - 1; i++)
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
            return false;
    return true;
}


bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0;
    for (int i = 0; i < (int)P.size() - 1; i++) {
        if (ccw(pt, P[i], P[i+1])) sum += angle(P[i], pt, P[i+1]); // Left turn
        else sum -= angle(P[i], pt, P[i+1]); // Right turn
    }
    return fabs(fabs(sum) - 2*PI) < EPS;
}

// Cortar Polígono com linha ab [cite: 1294]
point lineIntersectSeg(point p, point q, point A, point B) {
    // Função auxiliar para encontrar interseção (simplificada para o exemplo)
    // Assume-se que a interseção existe baseada na lógica de cutPolygon
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
        if (i != (int)Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) P.push_back(Q[i]); // Q[i] está à esquerda
        if (left1 * left2 < -EPS) // Aresta cruza a linha
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front())) P.push_back(P.front());
    return P;
}



// CIRCULOS

double insideCircle(point p, point c, double r) {
    double dx = p.x - c.x, dy = p.y - c.y;
    double Euc = dx * dx + dy * dy, rSq = r*r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2; //inside/border/outside
}

bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
                (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0) return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true; // to get the other center, reverse p1 and p2
}

// TRIANGULOS

double rInCircle(point a, point b, point c) {
    vector<point> vt = {a,b,c};
    return area(vt) / (0.5 * perimeter(vt));
}

int inCircle(point p1, point p2, point p3, point &ctr, double &r){
    r = rInCircle(p1, p2, p3);
    if(fabs(r) < EPS) return 0;
    
    line l1, l2; // compute these two angle bisectors
    double ration = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2,scale(toVec(p2,p3), ration/(1+ration)));
    pointsToLine(p1, p, l1);

    ration = dist(p2,p1) / dist(p2,p3);
    p = translate(p1,scale(toVec(p1,p3), ration / (1 + ration)));
    pointsToLine(p2, p, l2);

    //get their intersection point
    areIntersect(l1, l2, ctr);
    return 1;
}

double rInCircle(point a, point b, point c) {
    vector<point> vt = {a,b,c};
    return dist(a,b) * dist(b,c) * dist(c,a) / (4 * area(vt));
}

point pivot(0,0);
//angle-sorting function
bool angleCmp(point a, point b) {
    //spacial case
    if(collinear(pivot, a, b))
        return dist(pivot,a) < dist(pivot,b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y,d1x) - atan2(d2y,d2x)) < 0; //compare two angles
}

//convex hull
vector<point> CH(vector<point> P){
    int i,j,n = (int)P.size();
    //special case, the CH is P itself
    if(n <= 3) {
        if(!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }

    int P0 = 0;
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
    S.push_back(P[n-1]);
    S.push_back(P[0]);
    P.push_back(P[1]);
    
    i=2;
    while(i<n){
        j = (int)S.size() -1;
        if(ccw(S[j-1],S[j],P[i])) 
            S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}


