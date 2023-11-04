#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<T> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, 0);
    }

    T combine(const T& x, const T& y) {
        return (x > y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        lazy[v] = 0;
        if (s == e) {
            t[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void upd(T& cur, T val) {
        cur += val;
    }

    void push(int v, int s, int e) {
        if (lazy[v] == 0 || s == e) return;
        upd(t[v << 1], lazy[v]);
        upd(t[v << 1 | 1], lazy[v]);
        upd(lazy[v << 1], lazy[v]);
        upd(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = 0;
    }

    void update(int v, int s, int e, int l, int r, T val) {
        if (l > r) return;
        if (l == s && e == r) {
            upd(t[v], val);
            upd(lazy[v], val);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, min(r, mid));
        T p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
};

const int N = 5e5 + 5;
const long long TERM = -1e18;

SegtreeLazy<N, long long, TERM> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<pair<int, long long>>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    vector<long long> d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    int m = 2 * n;
    vector<int> eul(m + 1);
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int tim = 0;

    function<void(int, int)> tour = [&](int u, int p) {
        tin[u] = ++tim;
        eul[tim] = u;
        for (auto [v, _] : adj[u]) {
            if (v == p) {
                continue;
            }
            tour(v, u);
        }
        tout[u] = ++tim;
        eul[tim] = u;
    };

    vector<long long> dp(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        for (auto [v, w] : adj[u]) {
            if (v == p) {
                continue;
            }
            dp[v] = dp[u] - d[u] + w + d[v];
            dfs(v, u);
        }
    };

    vector<long long> ans(n + 1);

    function<void(int, int)> reroot = [&](int u, int p) {
        ans[u] = max(ans[u], sgt.get(1, 1, m, 1, tin[u] - 1));
        ans[u] = max(ans[u], sgt.get(1, 1, m, tin[u] + 1, tout[u] - 1));
        ans[u] = max(ans[u], sgt.get(1, 1, m, tout[u] + 1, m));
        for (auto [v, w] : adj[u]) {
            if (v == p) {
                continue;
            }
            sgt.update(1, 1, m, 1, m, w);
            sgt.update(1, 1, m, tin[v], tout[v], -w * 2);
            reroot(v, u);
            sgt.update(1, 1, m, 1, m, -w);
            sgt.update(1, 1, m, tin[v], tout[v], w * 2);
        }
    };

    dp[1] = d[1];
    dfs(1, 1);
    tour(1, 1);
    vector<long long> values(m + 1);
    for (int i = 1; i <= m; i++) {
        values[i] = dp[eul[i]];
    }
    sgt.build(1, 1, m, values);
    reroot(1, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}