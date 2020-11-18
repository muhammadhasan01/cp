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

const int N = 1e6 + 5;
const long long INF = 1e18;

int n;
long long r1, r2, r3, d;
long long a[N];
long long dp[N][2]; // (Finish the boss, Remain the boss to live)

void upd(long long& x, long long y) {
    x = min(x, y);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r1 >> r2 >> r3 >> d;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            dp[i][j] = INF;
        }
    }

    auto finishBoss = [&](int i) -> long long {
        return r1 * a[i] + r3;
    };

    auto remainBoss = [&](int i) -> long long {
        return min(r1 * a[i] + r1, r2);
    };

    dp[1][0] = finishBoss(1), dp[1][1] = remainBoss(1);
    for (int i = 2; i <= n; i++) {
        // 0 -> 0
        upd(dp[i][0], dp[i - 1][0] + d + finishBoss(i));

        // 1 -> 0
        upd(dp[i][1], dp[i - 1][0] + d + remainBoss(i));

        // 0 -> 1
        upd(dp[i][0], dp[i - 1][1] + d + finishBoss(i) + d + r1 + d);
        upd(dp[i][0], dp[i - 1][1] + d + remainBoss(i) + d + r1 + d + r1);

        // 1 -> 1
        upd(dp[i][1], dp[i - 1][1] + d + remainBoss(i) + d + r1 + d);

        // Special Case
        if (i == n) {
            upd(dp[i][0], dp[i - 1][1] + d + finishBoss(i) + d + r1);
        }
    }
    cout << dp[n][0] << '\n';

    return 0;
}