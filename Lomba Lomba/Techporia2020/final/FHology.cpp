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

const int N = 1e5 + 5;

int n, m;
int power[N];
int par[N], dp[N], bucket[N], root;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
    }
    root = sqrt(n) + 1;
    for (int i = n; i >= 1; i -= root) {
        for (int j = i; j > max(i - root, 0); j--) {
            bucket[j] = i;
            if (j + power[j] > n) {
                dp[j] = 1;
                par[j] = j;
            } else if (j + power[j] <= i) {
                dp[j] = 1 + dp[j + power[j]];
                par[j] = par[j + power[j]];
            } else {
                dp[j] = 1;
                par[j] = j + power[j];
            }
        }
    }
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int a, b;
            cin >> a >> b;
            power[a] = b;
            for (int i = bucket[a]; i > max(bucket[a] - root, 0); i--) {
                if (i + power[i] > n) {
                    dp[i] = 1;
                    par[i] = i;
                } else if (i + power[i] <= bucket[a]) {
                    dp[i] = 1 + dp[i + power[i]];
                    par[i] = par[i + power[i]];
                } else {
                    dp[i] = 1;
                    par[i] = i + power[i];
                }
            }
        } else {
            int a;
            cin >> a;
            int ans = dp[a], lastpar = a;
            while (par[a] != a) {
                if (bucket[a] != bucket[par[a]])
                    ans += dp[par[a]];
                a = par[a];
                lastpar = a;
            }
            cout << lastpar << " " << ans << '\n';
        }
    }

    return 0;
}