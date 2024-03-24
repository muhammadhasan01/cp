#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, 0);
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

struct EulerTour {
    int n;
    vector<int> tin;
    vector<int> tout;
    vector<int> eul;
 
    EulerTour(int t_n) : n(t_n), tin(t_n), tout(t_n), eul(2 * t_n + 1) {}
    EulerTour(int root, vector<vector<int>>& adj) : EulerTour((int) adj.size()) {
        build(root, adj);
    }
 
    void build(int root, vector<vector<int>>& adj) {
        int tim = 0;
        
        function<void(int, int)> dfs = [&](int u, int p) {
            tin[u] = ++tim;
            eul[tim] = u;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
            }
            tout[u] = ++tim;
            eul[tim] = u;
        };
        
        dfs(root, root);
    }
};

const int N = 6e5;
const int INF = 2e9;
SegtreeLazy<N, int, -INF> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> par(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        par[v] = u;
    }
    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }
    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
    }
    EulerTour et(n + 1);
    et.build(1, adj);
    vector<bool> checked(n + 1);
    vector<bool> deleted(n + 1);
    checked[1] = true;
    int len = 2 * n;
    int ans = 0;
    for (int x : queries) {
        if (sgt.get(1, 1, len, et.tin[x], et.tin[x]) > 0) {
            break;
        }
        while (!checked[x]) {
            int p = par[x];
            int pos = lower_bound(adj[p].begin(), adj[p].end(), x) - adj[p].begin() - 1;
            while (pos >= 0) {
                int u = adj[p][pos];
                if (deleted[u]) {
                    break;
                }
                deleted[u] = true;
                sgt.update(1, 1, len, et.tin[u], et.tout[u], 1);
                --pos;
            }
            checked[x] = true;
            x = p;
        }
        ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}