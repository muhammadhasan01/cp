#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, m, q;
int sz;
int t[4 * N];
bitset<4 * N> lazy;
int par[N], ans[N];
vector<int> g[N];
vector<int> info[N];
bool good[N];

int fpar(int x) {
    return (par[x] == x ? x : par[x] = fpar(par[x]));
}

void merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu > pv) swap(pu, pv);
    par[pv] = pu;
}

void push(int v, int s, int e) {
    if (s == e) return;
    if (lazy[v] == 0) return;
    int mid = (s + e) >> 1;
    t[v << 1] = (mid - s + 1) - t[v << 1];
    t[v << 1 | 1] = (e - mid) - t[v << 1 | 1];
    lazy[v << 1] = !(lazy[v << 1]);
    lazy[v << 1 | 1] = !(lazy[v << 1 | 1]);
    lazy[v] = 0;
}

void updateRange(int v, int s, int e, int l, int r) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] = (e - s + 1) - t[v];
        lazy[v] = !(lazy[v]);
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid));
    updateRange(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
    t[v] = t[v << 1] + t[v << 1 | 1];
}

int get(int v, int s, int e, int l, int r) {
    if (l > r) return 0;
    if (l <= s && e <= r) {
        return t[v];
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    return get(v << 1, s, mid, l, min(r, mid)) + 
           get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
}

void process(int i, const vector<int>& v, bool take) {
    if (v.empty()) return;
    if (v[0] == 3) {
        int pos = v[1];
        updateRange(1, 1, sz, 1 + (pos - 1) * m, pos * m);
    } else {
        int x = v[1], y = v[2];
        int idx = (x - 1) * m + y;
        int now = get(1, 1, sz, idx, idx);
        bool flag = false;
        if (v[0] == 1 && take && !now) flag = true;
        if (v[0] == 2 && take && now) flag = true;
        if (take) good[i] = flag;
        else if (!take && good[i]) flag = true;
        if (flag) {
            updateRange(1, 1, sz, idx, idx);
        }
    }
}

void dfs(int u, int p) {
    process(u, info[u], true);
    ans[u] = get(1, 1, sz, 1, sz);
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    process(u, info[u], false);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    sz = n * m;
    iota(par, par + N, 0);
    int cur = 0;
    int tp, x, y, z;
    for (int i = 1; i <= q; i++) {
        cin >> tp;
        if (tp != 4) {
            g[cur].push_back(i);
            g[i].push_back(cur);
            info[i].push_back(tp);
            cin >> x;
            info[i].push_back(x);
            if (tp != 3) {
                cin >> y;
                info[i].push_back(y);
            }
            cur = i;
        } else {
            cin >> z;
            merge(i, z);
            cur = fpar(i);
        }
    }
    dfs(0, 0);
    for (int i = 1; i <= q; i++) {
        cout << ans[fpar(i)] << '\n';
    }

    return 0;
}