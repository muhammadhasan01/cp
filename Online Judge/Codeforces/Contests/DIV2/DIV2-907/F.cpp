#include <bits/stdc++.h>

using namespace std;

template<int MAXN, typename T, const T TERM>
struct SegtreeLazy {
    vector<T> t;
    vector<pair<long long, long long>> lazy;
    SegtreeLazy() {
        t.assign(4 * MAXN, TERM);
        lazy.assign(4 * MAXN, make_pair(0LL, 0LL));
    }

    T combine(const T& x, const T& y) {
        return x + y;
    }

    void build(int v, int s, int e) {
        lazy[v] = {0LL, 0LL};
        if (s == e) {
            t[v] = 0;
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v].second == 0 || s == e) return;
        if (lazy[v].second == 1) {
            int mid = (s + e) >> 1;
            t[v << 1] += 1LL * (mid - s + 1) * lazy[v].first;
            t[v << 1 | 1] += 1LL * (e - mid) * lazy[v].first;
        } else if (lazy[v].second == 2) {
            t[v << 1] = 0;
            t[v << 1 | 1] = 0;
        }
        if (lazy[v << 1].second == 1 && lazy[v].second == 1) {
            lazy[v << 1].first += lazy[v].first;
        } else {
            lazy[v << 1] = lazy[v];
        }
        if (lazy[v << 1 | 1].second == 1 && lazy[v].second == 1) {
            lazy[v << 1 | 1].first += lazy[v].first;
        } else {
            lazy[v << 1 | 1] = lazy[v];
        }
        lazy[v].second = 0;
    }

    void update(int v, int s, int e, int l, int r, pair<long long, long long> val) {
        if (l > r) return;
        if (l == s && e == r) {
            if (val.second == 1) {
                t[v] += 1LL * (e - s + 1) * val.first;
            } else if (val.second == 2) {
                t[v] = 0;
            }
            if (lazy[v].second == 1 && val.second == 1) {
                lazy[v].first += val.first;
            } else {
                lazy[v] = val;
            }
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
const long long TERM = 0;

SegtreeLazy<N, long long, TERM> sgt;

void solve() {
    int q;
    cin >> q;
    vector<tuple<int, int, int>> queries;
    int len = 1;
    for (int rep = 0; rep < q; rep++) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int u;
            cin >> u;
            queries.emplace_back(tp, u, ++len);
        } else if (tp == 2) {
            int u, x;
            cin >> u >> x;
            queries.emplace_back(tp, u, x);
        }
    }
    vector<vector<int>> adj(len + 5);
    for (auto& [tp, u, x] : queries) {
        if (tp == 1) {
            adj[u].emplace_back(x);
        }
    }

    int timer = 0;
    int m = 2 * len;
    vector<int> eul(m + 1);
    vector<int> tin(len + 1);
    vector<int> tout(len + 1);

    function<void(int)> dfs = [&](int u) {
        tin[u] = ++timer;
        eul[timer] = u;
        for (int v : adj[u]) {
            dfs(v);
        }
        tout[u] = ++timer;
        eul[timer] = u;
    };

    dfs(1);

    sgt.build(1, 1, m);
    for (auto& [tp, u, x] : queries) {
        if (tp == 1) {
            pair<long long, long long> val = make_pair(0, 2);
            sgt.update(1, 1, m, tin[x], tout[x], val);
        } else if (tp == 2) {
            pair<long long, long long> val = make_pair(x, 1);
            sgt.update(1, 1, m, tin[u], tout[u], val);
        }
    }
    for (int u = 1; u <= len; u++) {
        cout << sgt.get(1, 1, m, tout[u], tout[u]) << " \n"[u == len];
    }
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