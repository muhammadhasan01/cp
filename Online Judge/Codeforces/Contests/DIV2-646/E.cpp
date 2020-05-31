#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const pair<int, int> TERM = {-1, -1};
const pair<int, int> ZERO = {0, 0};

typedef pair<long long, int> pli;


int n;
int a[N], b[N], c[N];
vector<int> g[N];
pair<int, int> t[8 * N], lazy[8 * N];
int eul[2 * N], tin[N], tout[N], tim;

void dfs(int u, int p) {
    tin[u] = ++tim;
    eul[tim] = u;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++tim;
    eul[tim] = u;
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

void build(int v, int s, int e) {
    lazy[v] = TERM;
    if (s == e) {
        t[v].first = (b[eul[s]] == 1 && c[eul[s]] == 0);
        t[v].second = (b[eul[s]] == 0 && c[eul[s]] == 1);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

void push(int v, int s, int e) {
    if (lazy[v] == TERM) return;
    if (s == e) return;
    t[v << 1] = lazy[v];
    t[v << 1 | 1] = lazy[v];
    lazy[v << 1] = lazy[v];
    lazy[v << 1 | 1] = lazy[v];
    lazy[v] = TERM;
}

void updateRange(int v, int s, int e, int l, int r, const pair<int, int>& val) {
    if (l > r) return;
    if (l == s && e == r) {
        t[v] = val;
        lazy[v] = val;
        return;
    }
    push(v, s, e);
    int mid = (s + e) >> 1;
    updateRange(v << 1, s, mid, l, min(r, mid), val);
    updateRange(v << 1 | 1, mid + 1, e, max(mid + 1, l), r, val);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
}

pair<int, int> get(int v, int s, int e, int l, int r) {
    if (l > r) return ZERO;
    if (l <= s && e <= r) return t[v];
    push(v, s, e);
    int mid = (s + e) >> 1;
    return merge(get(v << 1, s, mid, l, min(r, mid)),
                 get(v << 1 | 1, mid + 1, e, max(mid + 1, l), r));
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    vector<int> cnt(2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        pq.push(make_pair(a[i], i));
        cnt[b[i]]++;
        cnt[c[i]]--;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    if (cnt[0] != 0 && cnt[1] != 0) {
        cout << -1 << '\n';
        return 0;
    }
    dfs(1, 1);
    n = 2 * n;
    build(1, 1, n);
    long long ans = 0;
    while (!pq.empty()) {
        pli temp = pq.top();
        long long cost = temp.first;
        int idx = temp.second;
        pq.pop();
        pair<int, int> getz = get(1, 1, n, tin[idx], tout[idx]);
        int v1 = getz.first / 2;
        int v2 = getz.second / 2;
        int mini = min(v1, v2);
        if (mini == 0) continue;
        ans += (2LL) * mini * cost;
        pair<int, int> makss = make_pair(v1 - mini, v2 - mini);
        updateRange(1, 1, n, tin[idx], tout[idx], ZERO);
        updateRange(1, 1, n, tin[idx], tin[idx], makss);
        updateRange(1, 1, n, tout[idx], tout[idx], makss);
    }
    cout << ans << '\n';

    return 0;
}