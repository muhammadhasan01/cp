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

const int N = 1e2 + 5;
const int R = 6e4 + 5;

int n, r;
int dp[N][R];
vector<pair<int, int>> v[2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        int a, b; cin >> a >> b;
        v[(b < 0)].emplace_back(a, b);
    }
    int answer = 0;
    {
        sort(v[0].begin(), v[0].end());
        int len = v[0].size();
        for (int i = 0; i < len; i++) {
            if (v[0][i].first > r) break;
            r += v[0][i].second;
            ++answer;
        }
    }
    {
        sort(v[1].begin(), v[1].end(), [&](auto x, auto y) {
            return x.first + x.second > y.first + y.second;
        });
        int len = v[1].size();
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j < R; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][r] = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = v[1][i - 1].first; j < R; j++) {
                for (int it = i - 1; it >= 0; it--) {
                    int before = dp[it][j];
                    if (before == -1) continue;
                    dp[i][j] = max(dp[i][j], before);
                    int new_j = j + v[1][i - 1].second;
                    if (new_j < 0) continue;
                    dp[i][new_j] = max(dp[i][new_j], 1 + before);
                }
            }
        }
        int cur_answer = 0;
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j < R; j++) {
                cur_answer = max(cur_answer, dp[i][j]);
            }
        }
        answer += cur_answer;
    }
    cout << answer << '\n';

    return 0;
}