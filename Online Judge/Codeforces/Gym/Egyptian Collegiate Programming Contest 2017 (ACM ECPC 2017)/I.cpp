#include <bits/stdc++.h>
using namespace std;
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

const int N = 201;
const int M = 2001;

int a[N][N];
int dp[N][N][M];

int get(int A, int B, int C, int D, int v) {
    return dp[C][D][v] - dp[A - 1][D][v] - dp[C][B - 1][v] + dp[A - 1][B - 1][v]; 
}

void solve() {
    int n, m, q;
    in(n), in(m), in(q);
    // cin >> n >> m >> q;
    int mini = M, maxi = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            in(a[i][j]);
            maxi = max(maxi, a[i][j]);
            mini = min(mini, a[i][j]);
            // cin >> a[i][j];
            for (int v = 1; v < M; v++) {
                dp[i][j][v] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> pre(M);
        for (int j = 1; j <= m; j++) {
            pre[a[i][j]]++;
            for (int v = mini; v <= maxi; v++) {
                dp[i][j][v] = dp[i - 1][j][v] + pre[v];
            }
        }
    }
    while (q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int cur = 0;
        int sz = (C - A + 1) * (D - B + 1);
        int bound = sz / 2 + 1;
        for (int v = mini; v <= maxi; v++) {
            int res = get(A, B, C, D, v);
            cur += res;
            if (cur >= bound) {
                printf("%d\n", v);
                break;
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("important.in", "r", stdin); 

    int tc;
    in(tc);
    for (int T = 1; T <= tc; T++) {
        printf("Case %d:\n", T);
        solve();
    }

    return 0;
}