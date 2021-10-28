#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int INF = 2e9;
const pair<int, int> TERM = make_pair(INF, -1);

template<int MAXN, typename T>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x < y ? x : y);
    }

    void build(int v, int s, int e, vector<T>& a) {
        if (s == e) {
            t[v] = a[s];
        } else {
            int mid = (s + e) >> 1;
            build(v << 1, s, mid, a);
            build(v << 1 | 1, mid + 1, e, a);
            t[v] = combine(t[v << 1], t[v << 1 | 1]);
        }
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] = val;
            return;
        }
        int mid = (s + e) >> 1;
        if (pos <= mid)
            update(v << 1, s, mid, pos, val);
        else
            update(v << 1 | 1, mid + 1, e, pos, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    T get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return TERM;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        T p1 = get(v << 1, s, mid, l, r);
        T p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
};

Segtree<N, pair<int, int>> sgt;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<pair<int, int>> dp(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i] = make_pair(INF, i);
    }
    dp[0] = make_pair(0, 0);
    sgt.build(1, 0, n, dp);
    vector<tuple<int, int, int>> pos(n);
    for (int i = 1; i <= n; i++) {
        int id = i + b[i];
        pos[i - 1] = make_tuple(id - a[id], id, i);
    }
    sort(pos.begin(), pos.end());
    vector<int> par(n + 1, -1);
    for (auto& [dist, place, i] : pos) {
        int l = place - a[place];
        int r = place;
        auto [val, j] = sgt.get(1, 0, n, l, r);
        val += 1;
        if (val > dp[i].first) {
            continue;
        }
        par[i] = j;
        dp[i].first = val;
        sgt.update(1, 0, n, i, dp[i]);
    }
    if (dp[n].first == INF) {
        cout << -1 << '\n';
        return;
    }
    vector<int> ans;
    {
        int i = n;
        while (true) {
            i = par[i];
            if (i < 0) {
                break;
            }
            ans.emplace_back(i);
        }
        if (ans.empty() || ans.back() != 0) {
            cout << -1 << '\n';
            return;
        }
    }
    int len = ans.size();
    cout << len << '\n';
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
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