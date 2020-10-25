#include <bits/stdc++.h>

using namespace std;

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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    const int INF = 2e9;
    const vector<string> NAME = {"Zulian", "Razzashi", "Hakkari", "Sandfury", "Skullsplitter",
                                 "Bloodscalp", "Gurubashi", "Vilebranch", "Witherbark"};
    int nums = NAME.size();
    map<string, int> mp;
    for (int i = 0; i < nums; i++) {
        mp[NAME[i]] = i;
    }
    vector<vector<pair<int, int>>> v(nums);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string str; int k, p;
        cin >> str >> k >> p;
        v[mp[str]].emplace_back(k, p);
    }
    vector<vector<int>> dp(nums, vector<int>(n + 1, -1));
    for (int i = 0; i < nums; i++) {
        dp[i][0] = 0;
        for (int j = 0; j < (int) v[i].size(); j++) {
            for (int val = n; val >= 0; val--) {
                if (dp[i][val] == -1) continue;
                int nval = min(n, val + v[i][j].first);
                if (dp[i][nval] == -1 || dp[i][nval] > dp[i][val] + v[i][j].second)
                    dp[i][nval] = dp[i][val] + v[i][j].second;
            }
        }
        for (int val = n - 1; val >= 0; val--) {
            if (dp[i][val + 1] == -1) continue;
            if (dp[i][val] == -1 || dp[i][val + 1] < dp[i][val]) dp[i][val] = dp[i][val + 1];
        }
        debug() << imie(v[i]);
        debug() << imie(i) imie(dp[i]);
    }
    vector<vector<int>> ans(3, vector<int>(n + 1, -1));
    for (int i = 0; i < 3; i++) {
        for (int val = 0; val <= n; val++) {
            bool ok = true;
            int res = 0;
            for (int j = 0; j < 3; j++) {
                int x = 3 * i + j;
                if (dp[x][val] == -1) {
                    ok = false;
                    break;
                }
                res += dp[x][val];
            }
            if (!ok) continue;
            ans[i][val] = res;
        }
        debug() << imie(i) imie(ans[i]);
    }
    int answer = INF;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            int k = (n - i) - j;
            if (ans[0][i] == -1 || ans[1][j] == -1 || ans[2][k] == -1) continue;
            answer = min(answer, ans[0][i] + ans[1][j] + ans[2][k]);
            debug() << imie(i) imie(j) imie(k) imie(answer);
        }
    }
    if (answer == INF) {
        cout << "impossible" << '\n';
        return 0;
    }
    cout << answer << "\n";

    return 0;
}