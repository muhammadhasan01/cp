#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int INF = 2e9;

int n, q;
int a[N];
int last[N];
int pre[N], suf[N];
int ql[N], qr[N];
vector<tuple<int, int, int>> t[4 * N];
vector<pair<int, int>> upper[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = vector<tuple<int, int, int>>(1, make_tuple(pre[s], suf[s], a[s]));
        upper[v] = vector<pair<int, int>>(1, make_pair(suf[s], a[s]));
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    merge(t[v << 1].begin(), t[v << 1].end(), t[v << 1 | 1].begin(), t[v << 1 | 1].end(), back_inserter(t[v]));
    int len = t[v].size();
    upper[v].resize(len);
    for (int i = 0; i < len; i++) {
        auto [l, r, id] = t[v][i];
        upper[v][i] = make_pair(r, id);
        if (i > 0) {
            upper[v][i] = max(upper[v][i], upper[v][i - 1]);
        }
    }
}

pair<int, int> query(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) {
        return make_pair(-INF, -INF);
    }
    if (l <= s && e <= r) {
        int len = t[v].size();
        int tl = 0, tr = len - 1, at = -1;
        while (tl <= tr) {
            int mid = (tl + tr) >> 1;
            if (get<0>(t[v][mid]) < l) {
                tl = mid + 1;
                at = mid;
            } else {
                tr = mid - 1;
            }
        }
        if (at == -1) {
            return make_pair(-INF, -INF);
        }
        return upper[v][at];
    }
    int mid = (s + e) >> 1;
    return max(query(v << 1, s, mid, l, r), query(v << 1 | 1, mid + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> ql[i] >> qr[i];
    }
    for (int i = 1; i <= n; i++) {
        pre[i] = last[a[i]];
        last[a[i]] = i;
    }
    for (int i = 0; i < N; i++) {
        last[i] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = last[a[i]];
        last[a[i]] = i;
    }
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int l = ql[i], r = qr[i];
        auto [up, id] = query(1, 1, n, l, r);
        if (r >= up) {
            cout << 0 << '\n';
            continue;
        }
        cout << id << '\n';
    }

    return 0;
}