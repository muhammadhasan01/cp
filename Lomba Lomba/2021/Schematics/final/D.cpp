#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;
const int M = 2 * N;

int n, q;
int a[N];
int eul[M];
int tin[M], tout[M], tim;
int t[4 * M];
vector<int> adj[N];

void dfs(int u, int p) {
    tin[u] = ++tim;
    eul[tim] = a[u];
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
    tout[u] = ++tim;
    eul[tim] = a[u];
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = eul[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

void update(int v, int s, int e, int pos, int val) {
    if (s == e && s == pos) {
        t[v] = val;
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, val);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, val);
    }
    t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) {
        return 0;
    }
    if (l <= s && e <= r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return p1 + p2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = (a[i] < 0 ? 1 : 0);
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(1, 1);
    int m = 2 * n;
    build(1, 1, m);
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x, y;
            cin >> x >> y;
            a[x] = (y < 0 ? 1 : 0);
            update(1, 1, m, tin[x], a[x]);
            update(1, 1, m, tout[x], a[x]);
        } else if (tp == 2) {
            int x;
            cin >> x;
            int qr = get(1, 1, m, tin[x], tout[x]) / 2;
            cout << (qr % 2 == 0 ? "Untung" : "Rugi") << '\n';
        }
    }

    return 0;
}