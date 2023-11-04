#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int numComponent = adj[1].size();
    vector<int> atComp(n + 1);
    vector<int> idxComp(n + 1);
    vector<vector<int>> comp(numComponent + 1);
    int posComp = 1;
    function<void(int, int)> dfs = [&](int u, int p) {
        comp[posComp].emplace_back(u);
        atComp[u] = posComp;
        idxComp[u] = (int) comp[posComp].size();
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
        }
    };
    for (int u : adj[1]) {
        dfs(u, 1);
        posComp = posComp + 1;
    }
    int addZero = 0;
    vector<BIT<int>> bits;
    bits.emplace_back(BIT<int>(n + 5));
    vector<int> lens(numComponent + 1);
    for (int num = 1; num <= numComponent; num++) {
        lens[num] = (int) comp[num].size();
        bits.emplace_back(BIT<int>(lens[num] + 5));
    }

    auto handleUpdate = [&](int u, int x, int d) -> void {
        if (u == 1) {
            bits[0].add(1, x);
            bits[0].add(d + 1, -x);
            return;
        }
        int numComp = atComp[u];
        int idx = idxComp[u];
        int L = idx - d;
        int R = idx + d;
        if (L >= 1) {
            bits[numComp].add(L, x);
        } else {
            int mn = -L;
            if (mn == 0) {
                addZero += x;
                bits[numComp].add(1, x);
            } else if (mn > 0) {
                bits[0].add(1, x);
                bits[0].add(mn + 1, -x);
                if (mn + 1 <= lens[numComp]) {
                    bits[numComp].add(mn + 1, x);
                }
            }
        }
        if (R + 1 <= lens[numComp]) {
            bits[numComp].add(R + 1, -x);
        }
    };

    auto handleQuery = [&](int u) -> void {
        if (u == 1) {
            int res = addZero + bits[0].get(1);
            cout << res << '\n';
            return;
        }
        int numComp = atComp[u];
        int idx = idxComp[u];
        int res = bits[numComp].get(idx) + bits[0].get(idx);
        cout << res << '\n';
    };

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int u, x, d;
            cin >> u >> x >> d;
            handleUpdate(u, x, d);
        } else if (tp == 1) {
            int u;
            cin >> u;
            handleQuery(u);
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}