#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e9;
const pair<int, int> TERM = {-INF, 0};

int n, m;
int w[N];
int cnt[N];
bool vis[N];
vector<int> g[N];
pair<int, int> p[N];
pair<int, int> t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = make_pair(cnt[s], s);
    } else {
        int mid = (s + e) >> 1;
        build(v << 1, s, mid);
        build(v << 1 | 1, mid + 1, e);
        t[v] = max(t[v << 1], t[v << 1 | 1]);
    }
}

void update(int v, int s, int e, int pos, bool rep) {
    if (s == e && s == pos) {
        if (rep) {
            t[v].first = -INF;
        } else {
            t[v].first++;
        }
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid) {
        update(v << 1, s, mid, pos, rep);
    } else {
        update(v << 1 | 1, mid + 1, e, pos, rep);
    }
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}

pair<int, int> get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return TERM;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    return max(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

void dismiss() {
    puts("DEAD");
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        cnt[i] += (w[i] + 1);
    }
    for (int i = 1; i <= m; i++) {
        cin >> p[i].first >> p[i].second;
        cnt[p[i].first]--;
        cnt[p[i].second]--;
        g[p[i].first].emplace_back(i);
        g[p[i].second].emplace_back(i);
    }
    build(1, 1, n);
    int cnt = 0;
    deque<int> ans;
    while (true) {
        pair<int, int> cur = get(1, 1, n, 1, n);
        if (cur.first <= 0) dismiss();
        for (auto e : g[cur.second]) {
            if (vis[e]) continue;
            ++cnt;
            vis[e] = 1;
            int res = p[e].first;
            if (res == cur.second) res = p[e].second;
            update(1, 1, n, res, false);
            ans.emplace_front(e);
        }
        if (cnt == m) break;
        update(1, 1, n, cur.second, true);
    }
    cout << "ALIVE" << '\n';
    for (int i = 0; i < m; i++) {
        cout << ans[i] << (i == m - 1 ? '\n' : ' ');
    }

    return 0;
}