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

/** START OF TEMPLATE DEBUGGER **/
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
/** END OF TEMPLATE DEBUGGER **/

const int N = 85;
const int INF = 1e7;

int n, k, m;
int dp[N][N][N][N];
int res[N][N];

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i][j] = INF;
        }
    }
    in(n), in(k), in(m);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        in(u), in(v), in(c);
        res[u][v] = min(res[u][v], c);
    }
    for (int a = 0; a < N; a++) {
        for (int b = 0; b < N; b++) {
            for (int c = 0; c < N; c++) {
                for (int d = 0; d < N; d++) {
                    dp[a][b][c][d] = INF;
                }
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        dp[1][0][n + 1][u] = 0;
    }
    for (int a = 1; a < k; a++) {
        for (int b = 0; b <= n + 1; b++) {
            for (int c = b + 1; c <= n + 1; c++) {
                for (int u = max(1, b); u <= min(n, c); u++) {
                    int val = dp[a][b][c][u];
                    if (val == INF) continue;
                    for (int v = b + 1; v < u; v++) {
                        int& cur = dp[a + 1][b][u][v];
                        cur = min(cur, res[u][v] + val);
                    }
                    for (int v = u + 1; v < c; v++) {
                        int& cur = dp[a + 1][u][c][v];
                        cur = min(cur, res[u][v] + val);
                    }
                }
            }
        }
    }
    int ans = INF;
    for (int b = 0; b <= n + 1; b++) {
        for (int c = b + 1; c <= n + 1; c++) {
            for (int u = max(1, b); u <= min(n, c); u++) {
                ans = min(ans, dp[k][b][c][u]);
            }
        }
    }
    if (ans == INF) ans = -1;
    cout << ans << '\n';

    return 0;
}