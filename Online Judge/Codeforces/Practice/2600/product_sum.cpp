#include <bits/stdc++.h>

using namespace std;

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

const int N = 2e5 + 5;

int n, a[N];
long long pre[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
        ans += 1LL * i * a[i]; 
    }
    long long dif = 0;
    // right cyclic [l, r] => a[r] * l - pre[l - 1] + pre[r - 1] - a[r] * r
    // finding maximum of { j * a[i] - pre[j - 1] + pre[i - 1] - a[i] * i }
    // y = mx + c
    // m = j, c = -pre[j - 1] 
    LineContainer rgt;
    for (int i = 2; i <= n; i++) {
        rgt.add(i - 1, -pre[i - 2]);
        dif = max(dif, rgt.query(a[i]) + pre[i - 1] - 1LL * i * a[i]);
    }
    // left cyclic [l, r] => a[l] * r - pre[r] + pre[l] - a[i] * i
    // finding maximum of { j * a[i] - pre[j] + pre[i] - a[i] * i }
    // y = mx + c
    // m = j, c = -pre[j]
    LineContainer lft;
    for (int i = n - 1; i >= 1; i--) {
        lft.add(i + 1, -pre[i + 1]);
        dif = max(dif, lft.query(a[i]) + pre[i] - 1LL * i * a[i]);
    }
    cout << ans + dif << '\n';

    return 0;
}