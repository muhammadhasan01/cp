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

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 5;
const int HS = 3;
const int K = 10;

int n, m, k;
vector<pair<int, int>> adj[N];
int mod[HS];
int ans;

struct hash_num {
    int vals[HS];
    hash_num() {
        memset(vals, 0, sizeof(vals));
    }

    hash_num(long long x) {
        for (int i = 0; i < HS; i++) {
            vals[i] = (x % mod[i] + mod[i]) % mod[i];
        }
    }

    hash_num operator+(hash_num x) {
        hash_num res = hash_num(0);
        for (int i = 0; i < HS - 1; i++) {
            res.vals[i] = (vals[i] + x.vals[i]) % mod[i];
        }
        res.vals[HS - 1] = (1LL * vals[HS - 1] * x.vals[HS - 1]) % mod[HS - 1];
        return res;
    }

    bool operator==(hash_num x) {
        for (int i = 0; i < HS; i++) {
            if (vals[i] != x.vals[i])
                return false;
        }
        return true;
    }
} dp[K][K], values[N], sum;

void init() {
    uniform_int_distribution<int> rg(1e8, 1e9);
    for (int i = 0; i < HS; i++) {
        mod[i] = rg(rng32);
    }
}

void dfs(int u, hash_num x) {
    if (u == k) {
        if (x == sum) ++ans;
        return;
    }
    for (int v = 1; v <= u + 1; v++) {
        dfs(u + 1, x + dp[u + 1][v]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    init();
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(w, v);
    }
    uniform_int_distribution<long long> rg(1, 1e18);
    for (int i = 0; i < n; i++) {
        values[i] = hash_num(rg(rng32));
        sum = sum + values[i];
    }
    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
        int len = adj[i].size();
        for (int j = 1; j <= len; j++) {
            dp[len][j] = dp[len][j] + values[adj[i][j - 1].second];
        }
    }
    dfs(0, hash_num(0));
    cout << ans << '\n';

    return 0;
}