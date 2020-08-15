#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e6 + 5;

int tc;
int n, m;
int c[N];
long long t[4 * N];

void build(int v, int s, int e) {
    t[v] = INF;
    if (s == e) return;
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
}

void update(int v, int s, int e, int pos, long long val) {
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
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

long long get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r)
        return t[v];
    int mid = (s + e) >> 1;
    return min(get(v << 1, s, mid, l, r), get(v << 1 | 1, mid + 1, e, l, r));
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    if (m >= n) {
        cout << 0 << '\n';
        return; 
    }
    build(1, 1, n);
    update(1, 1, n, 1, 0LL);
    for (int i = 2; i < n; i++) {
        if (c[i] == 0) continue;
        long long res = min(INF, c[i] + get(1, 1, n, max(1, i - m), i - 1));
        update(1, 1, n, i, res);
    }
    long long answer = get(1, 1, n, max(1, n - m), n - 1);
    if (answer == INF) answer = -1;
    cout << answer << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // freopen("D2_input.txt", "r", stdin);
    // freopen("D2_output.txt", "w", stdout);

    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}