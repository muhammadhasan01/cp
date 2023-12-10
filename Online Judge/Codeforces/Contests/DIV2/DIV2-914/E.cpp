#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<T> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, 0LL);
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

const int N = 1e6 + 5;
const long long INF = 1e18;
const long long ADD = 1e7;

SegtreeLazy<N, long long, -INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<vector<int>> queries(n + 1);
    vector<vector<int>> removed(q);
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        queries[x].emplace_back(i);
        int k;
        cin >> k;
        removed[i].resize(k);
        for (int& u : removed[i]) {
            cin >> u;
        }
    }
    vector<int> depth(n + 1);
    vector<int> tin(n + 1);
    vector<int> tout(n + 1);
    int m = 2 * n;
    vector<int> eul(m + 1);
    int tim = 0;

    function<void(int, int)> dfs = [&](int u, int p) {
        tin[u] = ++tim;
        eul[tim] = u;
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            depth[v] = 1 + depth[u];
            dfs(v, u);
        }
        tout[u] = ++tim;
        eul[tim] = u;
    };

    dfs(1, 1);

    {
        vector<long long> init(m + 1);
        for (int i = 1; i <= m; i++) {
            init[i] = depth[eul[i]];
        }
        sgt.build(1, 1, m, init);
    }

    auto isAncestor = [&](int u, int v) -> bool {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    };

    vector<long long> ans(q);
    int lastNode = -1;
    
    function<void(int, int)> process = [&](int u, int p) {
        for (int i : queries[u]) {
            vector<tuple<int, int, long long>> updates;
            for (int v : removed[i]) {
                if (v == 1) {
                    sgt.update(1, 1, m, 1, tin[lastNode] - 1, -ADD);
                    sgt.update(1, 1, m, tout[lastNode] + 1, m, -ADD);
                    updates.emplace_back(1, tin[lastNode] - 1, -ADD);
                    updates.emplace_back(tout[lastNode] + 1, m, -ADD);
                } else if (isAncestor(v, u)) {
                    sgt.update(1, 1, m, 1, tin[v], -ADD);
                    sgt.update(1, 1, m, tout[v], m, -ADD);
                    updates.emplace_back(1, tin[v], -ADD);
                    updates.emplace_back(tout[v], m, -ADD);
                } else {
                    sgt.update(1, 1, m, tin[v], tout[v], -ADD);
                    updates.emplace_back(tin[v], tout[v], -ADD);
                }
            }
            ans[i] = sgt.get(1, 1, m, 1, m);
            for (auto [s, e, val] : updates) {
                sgt.update(1, 1, m, s, e, -val);
            }
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            if (u == 1) {
                lastNode = v;
            }
            sgt.update(1, 1, m, 1, m, 1LL);
            sgt.update(1, 1, m, tin[v], tout[v], -2LL);
            process(v, u);
            sgt.update(1, 1, m, 1, m, -1LL);
            sgt.update(1, 1, m, tin[v], tout[v], 2LL);
        }
    };

    process(1, 1);
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}