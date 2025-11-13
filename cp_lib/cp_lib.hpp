#ifndef CP_LIB_HPP
#define CP_LIB_HPP

// ==================== Includes padrão ====================
#include <bits/stdc++.h>
using namespace std;

// ==================== Type definitions ====================
using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vvii = vector<vii>;

// ==================== Constantes úteis ====================
const int INF = 1e9 + 7;
const ll LINF = 1e18;
const int MAXN = 1e5 + 5;

// ==================== Defines para DFS/BFS ====================
#define VISITED 1
#define UNVISITED 0

// ==================== Defines para grafos bipartidos ====================
#define BLANK 0
#define BLACK 2
#define RED 4

// ==================== Macros úteis ====================
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= a; --i)

#endif // CP_LIB_HPP
