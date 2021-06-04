#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
long long a[N];
long long b[N];

struct Line {
    mutable long long m, c, p;
    bool operator<(const Line& o) const {
        return m < o.m;
    }
    bool operator<(long long x) const {
        return p < x;
    }
};

struct LineContainer: multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const long long INF = LLONG_MAX;
    long long div(long long a, long long b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = INF, 0;
        if (x->m == y->m) x->p = x->c > y->c ? INF : -INF;
        else x->p = div(y->c - x->c, x->m - y->m);
        return x->p >= y->p;
    }

    void add(long long m, long long c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    LineContainer lc;
    // dp[i] = a[i] * b[j] + dp[j]
    long long dp = 0;
    lc.add(-b[1], -dp);
    for (int i = 1; i <= n; i++) {
        dp = -lc.query(a[i]);
        lc.add(-b[i], -dp);
    }
    cout << dp << '\n';

    return 0;
}