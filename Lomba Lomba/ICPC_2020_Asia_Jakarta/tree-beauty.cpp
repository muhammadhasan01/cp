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

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int sz) : n(sz), bit(sz + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].emplace_back(i);
    }
    BIT<long long> sub_one(n), sub_mone(n), anc_one(n);
    vector<int> tin(n + 1), tout(n + 1);
    int tim = 0;
    int logs = ceil(log2(n)) + 2;
    vector<int> dep(n + 1);
    vector<vector<int>> pos(n + 1);
    vector<vector<long long>> desc(n + 1, vector<long long>(logs));

    function<void(int, int)> dfs = [&](int u, int d) {
        tin[u] = ++tim, dep[u] = d;
        pos[d].emplace_back(tim);
        for (int v : adj[u])
            dfs(v, d + 1);
        tout[u] = tim;
    };

    dfs(1, 1);

    auto update_one = [&](int u, long long val) -> void {
        sub_one.add(tin[u], val * (tout[u] - tin[u] + 1));
        anc_one.add(tin[u] + 1, val);
        anc_one.add(tout[u] + 1, -val);
    };

    auto get_counts = [&](int u) -> vector<int> {
        vector<int> ret(logs);
        int depth = dep[u];
        for (int i = 0; i < logs; i++) {
            int cur = depth + i;
            if (cur > n) break;
            auto lft = lower_bound(pos[cur].begin(), pos[cur].end(), tin[u]);
            auto rgt = upper_bound(pos[cur].begin(), pos[cur].end(), tout[u]);
            ret[i] = (int) (rgt - lft);
        }
        return ret;
    };

    auto update_mone = [&](int u, long long val, int k) -> void {
        vector<int> cnts = get_counts(u);
        long long cur = val, sum = 0;
        for (int i = 0; i < logs; i++) {
            desc[u][i] += cur;
            sum += cur * cnts[i];
            cur /= k;
        }
        sub_mone.add(tin[u], sum);
    };

    auto update = [&](int u, long long val, int k) -> void {
        if (k == 1)
            update_one(u, val);
        else
            update_mone(u, val, k);
    };

    auto query = [&](int u) -> long long {
        long long ret = 0;
        {
            ret += sub_one.query(tin[u], tout[u]);
            ret += anc_one.query(1, tin[u]) * (tout[u] - tin[u] + 1);
        }
        {
            ret += sub_mone.query(tin[u], tout[u]);
            vector<int> cnts = get_counts(u);
            for (int d = 1, cur = par[u]; d < logs; d++, cur = par[cur]) {
                for (int i = 0; i + d < logs; i++) {
                    ret += desc[cur][i + d] * cnts[i];
                }
            }
        }
        return ret;
    };

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update(x, y, k);
        } else if (tp == 2) {
            int x;
            cin >> x;
            cout << query(x) << '\n';
        }
    }

    return 0;
}