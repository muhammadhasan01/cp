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

const int N = 20;
const int K = 10;

long long cnt[N][K][2];
long long dp[N][K][2];

long long get(long long x) {
    deque<int> nums;
    while (x > 0) {
        nums.emplace_front(x % 10);
        x /= 10;
    }
    if (nums.empty()) {
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    memset(cnt, 0, sizeof(cnt));
    int len = nums.size();
    cnt[0][0][1] = 1;
    for (int i = 1; i <= len; i++) {
        int num = nums[i - 1];
        for (int x = 0; x < K; x++) {
            for (int d = 0; d < K; d++) {
                for (int equal = 0; equal < 2; equal++) {
                    if (equal && d > num) continue;
                    if (!cnt[i - 1][x][equal]) continue;
                    dp[i][d][(equal && d == num)] += (dp[i - 1][x][equal] + d * cnt[i - 1][x][equal]);
                    cnt[i][d][(equal && d == num)] += (cnt[i - 1][x][equal]);
                }
            }
        }
    }
    long long ans = 0;
    for (int d = 0; d < K; d++) {
        ans += (dp[len][d][0] + dp[len][d][1]);
    }
    return ans;
}

void solve() {
    long long l, r;
    cin >> l >> r;
    cout << get(r) - get(l - 1) << '\n';
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