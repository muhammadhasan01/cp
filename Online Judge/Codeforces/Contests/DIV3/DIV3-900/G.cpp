#include <bits/stdc++.h>

using namespace std;

template<class Info>
struct LCARMQ {
    int n, l;
    int tim;
    vector<int> depth, tin, tout;
    vector<vector<int>> up;
    vector<Info> val;
    vector<vector<Info>> sp;

    LCARMQ(int t_n, int root, const vector<vector<int>>& adj, const vector<Info>& values)
        : n(t_n), val(values), depth(t_n), tin(t_n), tout(t_n) {
        assert((int) values.size() == n);
        assert((int) adj.size() == n);
        l = ceil(log2(n)) + 2;
        up.assign(n, vector<int>(l));
        sp.assign(n, vector<Info>(l));
        function<void(int, int)> process = [&](int u, int p) {
            depth[u] = (u == p ? 0 : 1 + depth[p]);
            up[u][0] = p;
            sp[u][0] = val[u] + val[p];
            tin[u] = ++tim;
            for (int v : adj[u]) {
                if (v == p) {
                    continue;
                }
                process(v, u);
            }
            tout[u] = ++tim;
        };
        process(root, root);
        for (int i = 1; i < l; i++) {
            for (int u = 0; u < n; u++) {
                up[u][i] = up[up[u][i - 1]][i - 1];
                sp[u][i] = sp[u][i - 1] + sp[up[u][i - 1]][i - 1];
            }
        }
    }

    bool isAncestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }
    
    int lca(int u, int v) {
        if (isAncestor(u, v)) {
            return u;
        }
        if (isAncestor(v, u)) {
            return v;
        }
        for (int i = l - 1; i >= 0; i--) {
            if (!isAncestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0];
    }

    Info queryPath(int u, int v) {
        int w = lca(u, v);
        Info result = Info();
        for (int x : {u, v}) {
            result = result + val[x];
            for (int i = l - 1; i >= 0; i--) {
                if (depth[up[x][i]] >= depth[w]) {
                    result = result + sp[x][i];
                    x = up[x][i];
                }
            }
        }
        return result;
    }

    int distance(int u, int v) {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

struct Info {
    int val;
    Info() : val(0) {}
    Info(int v) : val(v) {}
};

Info operator+(const Info& lhs, const Info& rhs) {
    return Info(lhs.val | rhs.val);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    LCARMQ lcaRmq(n, 0, adj, vector<Info>(a.begin(), a.end()));

    auto answer = [&](int u, int v) -> void {
        set<int> candidates;
        int lca = lcaRmq.lca(u, v);
        candidates.emplace(lca);
        for (int x : {u, v}) {
            Info cur = a[x];
            while (lcaRmq.depth[x] > lcaRmq.depth[lca]) {
                candidates.emplace(x);
                for (int i = lcaRmq.l - 1; i >= 0; i--) {
                    if ((cur + lcaRmq.sp[x][i]).val == cur.val) {
                        x = lcaRmq.up[x][i];
                    }
                }
                x = lcaRmq.up[x][0];
                cur = (cur + a[x]);
            }
        }
        int ans = 0;
        for (int w : candidates) {
            int lft = __builtin_popcount(lcaRmq.queryPath(u, w).val);
            int rgt = __builtin_popcount(lcaRmq.queryPath(w, v).val);
            ans = max(ans, lft + rgt);
        }
        cout << ans << ' ';
    };

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        answer(u, v);
    }
    cout << '\n';
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