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

const int N = 75;

int n, m, k;
int a[N][N];
int dp[N][N][N][N];
int best[N][N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));
    memset(best, -1, sizeof(best));
    in(n), in(m), in(k);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            in(a[i][j]);
        }
    }
    best[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][0][0][0] = 0;
        for (int j = 1; j <= m; j++) {
            for (int t = 0; t <= m / 2; t++) {
                for (int x = 0; x < k; x++) {
                    if (dp[i][j - 1][t][x] == -1) continue;
                    dp[i][j][t][x] = max(dp[i][j][t][x], dp[i][j - 1][t][x]);
                    int& cur = dp[i][j][(t + 1)][(x + a[i][j]) % k];
                    cur = max(cur, dp[i][j - 1][t][x] + a[i][j]);
                }
            }
        }
        for (int x = 0; x < k; x++) {
            if (best[i - 1][x] == -1) continue;
            best[i][x] = max(best[i][x], best[i - 1][x]);
            for (int y = 0; y < k; y++) {
                int& cur = best[i][(x + y) % k];
                for (int t = 0; t <= m / 2; t++) {
                    if (dp[i][m][t][y] == -1) continue;
                    cur = max(cur, best[i - 1][x] + dp[i][m][t][y]);
                }
            }
        }
    }
    out(max(0, best[n][0]), '\n');

    return 0;
}