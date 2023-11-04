#include <bits/stdc++.h>

using namespace std;

struct point {
    long long x, y;
    point() {}
    point(long long _x, long long _y) : x(_x), y(_y) {}
    point operator-(const point& p) const { return point(x - p.x, y - p.y); }
    long long cross(const point& p) const { return x * p.y - y * p.x; }
    long long cross(const point& a, const point& b) const { return (a - *this).cross(b - *this); }
};

int sgn(const long long& x) {
    return x >= 0 ? x ? 1 : 0 : -1;
}

bool inter1(long long a, long long b, long long c, long long d) {
    if (a > b)
        swap(a, b);
    if (c > d)
        swap(c, d);
    return max(a, c) <= min(b, d);
}

bool check_inter(const point& a, const point& b, const point& c, const point& d) {
    if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
        return inter1(a.x, b.x, c.x, d.x) && inter1(a.y, b.y, c.y, d.y);
    return sgn(a.cross(b, c)) != sgn(a.cross(b, d)) &&
           sgn(c.cross(d, a)) != sgn(c.cross(d, b));
}

const int K = 4;

void solve() {
    vector<long long> x(K), y(K);
    for (int i = 0; i < K; i++) {
        cin >> x[i] >> y[i];
    }
    point A(x[0], y[0]);
    point B(x[0], y[1]);
    point C(x[1], y[1]);
    point D(x[1], y[0]);
    point E(x[2], y[2]);
    point F(x[3], y[3]);
    if (check_inter(A, B, E, F) || check_inter(B, C, E, F) || check_inter(C, D, E, F)|| check_inter(D, A, E, F)) {
        cout << "YA" << '\n';
    } else {
        cout << "TIDAK" << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}