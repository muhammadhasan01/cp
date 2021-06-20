#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const long long INF = 1e18;
const int N = 1e5 + 5;
const int M = 1e5 + 5;
const int P = 1e2 + 5;

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

int n, m, p;
int d[N];
int h[N], t[N];
long long a[M], s[M], dp[M][P];
LineContainer lc[P];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n), in(m), in(p);
    for (int i = 2; i <= n; i++) {
        in(d[i]);
    }
    for (int i = 1; i <= m; i++) {
        in(h[i]), in(t[i]);
    }
    for (int i = 2; i <= n; i++) {
        d[i] += d[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        a[i] = t[i] - d[h[i]];
        s[i] = a[i] + s[i - 1];
    }
    sort(a + 1, a + 1 + m);
    lc[0].add(-0, -0);
    // dp[i][j] = min{ -a[j] * k + dp[i - 1][k] + s[k] + a[j] * j - s[j] } (k < j)
    // y = mx + c
    // m = -k, c = dp[i - 1][k] + s[k]
    for (int i = 1; i <= m; i++) {
        for (int j = p; j >= 1; j--) {
            if (lc[j - 1].empty()) {
                dp[i][j] = INF;
            } else {
                dp[i][j] = -lc[j - 1].query(a[i]) + a[i] * i - s[i];
            }
            lc[j].add(-(-i), -(dp[i][j] + s[i]));
        }
    }
    out(dp[m][p], '\n');

    return 0;
}