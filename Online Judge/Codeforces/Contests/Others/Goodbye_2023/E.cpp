#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<int> lazy;
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

const int N = 6e5 + 5;
const int INF = 2e9;

SegtreeLazy<N, int, -INF> sgt;

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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].emplace_back(i);
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int m = 2 * n;
    {
        vector<int> init(m + 1);
        sgt.build(1, 1, m, init);
    }
    EulerTour et(1, adj);
    vector<set<int>> st(n + 1);
    long long ans = 1;

    function<void(int)> dfs = [&](int u) {
        for (int v : adj[u]) {
            dfs(v);
        }
        int x = a[u];
        for (auto it = st[x].upper_bound(et.tin[u]); it != st[x].end(); ) {
            if (*it >= et.tout[u]) {
                break;
            }
            int v = et.eul[*it];
            sgt.update(1, 1, m, et.tin[v], et.tout[v], -1);
            it = st[x].erase(it);
        }
        st[x].emplace(et.tin[u]);
        sgt.update(1, 1, m, et.tin[u], et.tout[u], 1);
        long long res = 1;
        for (int v : adj[u]) {
            long long cur = sgt.get(1, 1, m, et.tin[v], et.tout[v]);
            ans = max(ans, cur * res);
            res = max(res, cur);
        }
    };

    dfs(1);
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}