#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define tc template <class
tc T1, class T2 > ostream &operator<<(ostream &os, const pair<T1, T2> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
tc T, class = decay_t<decltype(*begin(declval<T>()))>, class = enable_if_t < !is_same<T, string>::value >> ostream &operator<<(ostream &os, const T &c) {
    os << '{';
    for (auto it = c.begin(); it != c.end(); ++it) os << &", "[2 * (it == c.begin())] << *it;
    return os << '}';
}
#define PARENS ()
#define EEE(...) EEE1(EEE1(__VA_ARGS__))
#define EEE1(...) EEE2(__VA_ARGS__)
#define EEE2(...) __VA_ARGS__
#define REP(macro, ...) __VA_OPT__(EEE(REP_HELPER(macro, __VA_ARGS__)))
#define REP_HELPER(macro, a1, ...) macro(a1) __VA_OPT__(REP_AGAIN PARENS(macro, __VA_ARGS__))
#define REP_AGAIN() REP_HELPER
#define out(x) "\t[" << #x " = " << x << "]\n"
#define debug(...) cerr << "Line " << __LINE__ << "\n" \
                        << REP(out, __VA_ARGS__) << "\n";

const ll INF = 1e18;

void el_psy_congroo() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    int S = *max_element(s.begin(), s.end());
    vector<priority_queue<pll>> Q(S + 1);
    vector<vector<ll>> dp(n + 1, vector<ll>(S + 1, INF));
    dp[1][s[1]] = 0;
    Q[s[1]].emplace(-dp[1][s[1]], 1);
    ll ans = INF;
    for (int x = S; x >= 1; x--) {
        while (!Q[x].empty()) {
            auto [dist, u] = Q[x].top();
            Q[x].pop();
            if (-dist != dp[u][x]) {
                continue;
            }
            for (auto [v, w] : adj[u]) {
                ll cur = dp[u][x] + x * w;
                for (int y : {x, min(x, s[v])}) {
                    if (dp[v][y] > cur) {
                        dp[v][y] = cur;
                        Q[y].emplace(-dp[v][y], v);
                    }
                }
            }
        }
        ans = min(ans, dp[n][x]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int TC = 1;
    cin >> TC;
    for (int i = 1; i <= TC; i++) {
        el_psy_congroo();
    }

    return 0;
}