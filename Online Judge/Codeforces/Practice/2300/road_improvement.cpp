#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;
const int N = 2e5 + 5;

struct Segtree {
    vector<long long> t;
    Segtree() {
        // do nothing
    }

    Segtree(int n) {
        t.assign(4 * n, 0);
    }

    long long combine(const long long& x, const long long& y) {
        return (x * y) % M;
    }

    void update(int v, int s, int e, int pos, long long val) {
        if (s == e && s == pos) {
            t[v] = val % M;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    long long get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return 1;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        long long p1 = get(v << 1, s, mid, l, r);
        long long p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

int n;
long long dp[N];
long long ans[N];
vector<int> adj[N];
Segtree sgt[N];

void dfs(int u, int p) {
    dp[u] = 1;
    int len = adj[u].size();
    for (int i = 0; i < len; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        dfs(v, u);
        sgt[u].update(1, 0, len - 1, i, 1 + dp[v]);
    }
    for (int v : adj[u]) {
        if (v == p) continue;
        dp[u] = (dp[u] * ((1 + dp[v]) % M)) % M;
    }
}

void rec(int u, int p) {
    int len = adj[u].size();
    ans[u] = sgt[u].get(1, 0, len - 1, 0, len - 1);
    for (int i = 0; i < len; i++) {
        int v = adj[u][i];
        if (v == p) continue;
        int pos = lower_bound(adj[v].begin(), adj[v].end(), u) - adj[v].begin();
        long long val = (sgt[u].get(1, 0, len - 1, 0, i - 1) * sgt[u].get(1, 0, len - 1, i + 1, len - 1)) % M;
        sgt[v].update(1, 0, (int) adj[v].size() - 1, pos, 1 + val);
        rec(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int u = 2; u <= n; u++) {
        int v;
        cin >> v;
        adj[v].emplace_back(u);
        adj[u].emplace_back(v);
    }
    for (int u = 1; u <= n; u++) {
        sgt[u] = Segtree((int) adj[u].size());
        sort(adj[u].begin(), adj[u].end());
    }
    dfs(1, 1);
    rec(1, 1);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }

    return 0;
}