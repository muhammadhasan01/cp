#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int N = 5e4 + 5;
const int M = 131069 + 69;
const int INF = 1e9 + 200;
const pii TERM = {INF, -INF};

int tc;
int n, q;
int a[N];
int ord[M], cnt;
pii t[2 * N];

pii merge(pii const& a, pii const& b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

void compress(int v, int s, int e) {
    ord[v] = cnt++;
    if (s == e) return;
    int mid = (s + e) >> 1;
    compress(v << 1, s, mid);
    compress(v << 1 | 1, mid + 1, e);
}

void build(int v, int s, int e) {
    if (s == e) {
        int val = a[s + 1] - a[s];
        t[ord[v]] = make_pair(val, val);
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[ord[v]] = merge(t[ord[v << 1]], t[ord[v << 1 | 1]]);
}

void update(int v, int s, int e, int pos) {
    if (s == e && s == pos) {
        int val = a[s + 1] - a[s];
        t[ord[v]] = make_pair(val, val);
        return;
    }
    int mid = (s + e) >> 1;
    if (pos <= mid)
        update(v << 1, s, mid, pos);
    else
        update(v << 1 | 1, mid + 1, e, pos);
    t[ord[v]] = merge(t[ord[v << 1]], t[ord[v << 1 | 1]]);
}

pii get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return TERM;
    if (l <= s && e <= r) return t[ord[v]];
    int mid = (s + e) >> 1;
    pii p1 = get(v << 1, s, mid, l, r);
    pii p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return merge(p1, p2);
}

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cnt = 0;
    if (--n > 0) compress(1, 1, n), build(1, 1, n);
    int tp, u, v;
    while (q--) {
        cin >> tp >> u >> v;
        if (tp == 1) {
            if (n == 0) continue;
            a[u] = v;
            if (u <= n) update(1, 1, n, u);
            if (u > 1) update(1, 1, n, u - 1);
        } else {
            if (u == v) {
                cout << "YES" << '\n';
                continue;
            }
            pii res = get(1, 1, n, u, v - 1);
            cout << (res.first == res.second ? "YES" : "NO") << '\n';
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }

    return 0;
}