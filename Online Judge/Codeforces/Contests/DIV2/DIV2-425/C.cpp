#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 5;
const long double LMAX = 1e6;
const long double eps = 1e-10;

struct st {
    long long t;
    long double x, v;
};

long long n;
long double s;
st p[N];

long double max(long double a, long double b) {
    return (a > b ? a : b);
}

long double min(long double a, long double b) {
    return (a < b ? a : b);
}

bool can(long double tim) {
    long long l1 = LMAX + 1, r1 = -1;
    long long l2 = LMAX + 1, r2 = -1;
    for (int i = 1; i <= n; i++) {
        if (p[i].t == 1 && p[i].v * tim >= p[i].x) {
            l1 = 0, r1 = LMAX;
        } else if (p[i].t == 2 && p[i].v * tim >= LMAX - p[i].x) {
            l2 = 0, r2 = LMAX;
        } else if (p[i].t == 1 && (p[i].v + s) * tim >= p[i].x) {
            l1 = min(l1, floorl(p[i].x));
            r1 = max(r1, floorl((tim * (s * s - p[i].v * p[i].v) + p[i].x * p[i].v) / s)); 
        } else if (p[i].t == 2 && (p[i].v + s) * tim >= LMAX - p[i].x) {
            l2 = min(l2, ceill(p[i].x - (tim * (s * s - p[i].v * p[i].v) + (p[i].v - s) * LMAX + (s - p[i].v) * p[i].x) / s));
            r2 = max(r2, floorl(p[i].x));
        }
    }
    return (l1 <= r1 && l2 <= r2 && l2 <= r1 && l1 <= r2);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].v >> p[i].t;
    }
    long double l = 0, r = LMAX;
    while (r - l > eps) {
        long double mid = (l + r) / 2.0;
        if (can(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(12) << r << '\n';

    return 0;
}