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

template<int MAXN, typename T, const T TERM>
struct Segtree {
    vector<T> t;
    int n;
    Segtree() {
        t.assign(4 * MAXN, 0);
    }

    void setN(int n) {
        this->n = n;
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(vector<T> &a) {
        for (int i = 1; i <= n; i++)
            t[n + i] = a[i];   
        for (int i = n; i >= 1; i--)
            t[i] = max(t[2 * i], t[2 * i + 1]);
    }

    T query(int l, int r) {
        T res = TERM;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
};

const int N = 150000 + 5;
const long long INF = 1e18;
Segtree<N, long long, -INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    long long d;
    in(n), in(m), in(d);
    sgt.setN(n);
    vector<tuple<long long, long long, long long>> v(m + 1);
    v[0] = make_tuple(0, 0, 1);
    for (int i = 1; i <= m; i++) {
        auto& [a, b, t] = v[i];
        in(a), in(b), in(t);
    }
    for (int i = 1; i <= m; i++) {
        auto& [a, b, t] = v[i];
        auto& [_, __, t_before] = v[i - 1];
        long long dif = (t - t_before) * d;
        vector<long long> dp(n + 1);
        for (int j = 1; j <= n; j++) {
            int l = (int) max(1LL, j - dif);
            int r = (int) min((long long) n, j + dif);
            dp[j] = (b - abs(a - j)) + sgt.query(l, r);
        }
        if (i == m) {
            out(*max_element(dp.begin() + 1, dp.end()), '\n');
            return 0;
        }
        sgt.build(dp);
    }
    
    return 0;
}