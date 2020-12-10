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
#ifdef LOCALE
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

const int N = 2e3 + 5;
const int K = 15;

int n;
int a[N][N];
int pre[N][K], suf[N][K];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x; cin >> x;
            a[i][j] = (x - '0');
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int d = 0; d <= 9; d++) {
            pre[i][d] = suf[i][d] = -1;
        }
        for (int j = 1; j <= n; j++) {
            int x = a[i][j];
            if (pre[i][x] == -1) {
                pre[i][x] = j;
            }
            suf[i][x] = j;
        }
    }
    for (int d = 0; d <= 9; d++) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i][d] == -1) continue;
            for (int j = 1; j <= n; j++) {
                if (suf[j][d] == -1) continue;
                debug() << imie(i) imie(j) imie(d);
                debug() << imie(pre[i][d]) imie(suf[j][d]);
                if (i == j) {
                    int dx = abs(pre[i][d] - suf[j][d]);
                    int dy = max(i - 1, n - i);
                    debug() << imie(dx) imie(dy);
                    ans = max(ans, dx * dy);
                } else {
                    {
                        int dx = abs(pre[i][d] - suf[j][d]);
                        int dy = max(max(i - 1, n - i), max(j - 1, n - j));
                        debug() << imie(dx) imie(dy);
                        ans = max(ans, dx * dy);
                    }
                    {
                        int dx = max(max(pre[i][d] - 1, n - pre[i][d]), max(suf[j][d] - 1, n - suf[j][d]));
                        int dy = abs(i - j);
                        ans = max(ans, dx * dy);
                    }
                }
                debug() << imie(ans);
            }
        }
        cout << ans << (d == 9 ? '\n' : ' ');
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}