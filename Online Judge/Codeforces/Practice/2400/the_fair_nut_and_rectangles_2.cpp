#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

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

int n;
tuple<int, int, long long> p[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y; long long a;
        cin >> x >> y >> a;
        p[i] = make_tuple(x, y, a);
    }
    sort(p + 1, p + 1 + n);
    // dp[i] = -x[j] * y[i] + dp[j] + x[i] * y[i] - a[i]
    // y = mx + c
    // m = -x[j], c = dp[j]
    LineContainer lc;
    long long dp = 0;
    long long ans = 0;
    lc.add(0, dp);
    for (int i = 1; i <= n; i++) {
        auto [x, y, a] = p[i];
        dp = lc.query(y) + 1LL * x * y - a;
        ans = max(ans, dp);
        lc.add(-x, dp);
    }
    cout << ans << '\n';

    return 0;
}