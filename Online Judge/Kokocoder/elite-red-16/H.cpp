#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int K = 20;
const int INF = 1e9;

struct Segtree {
    vector<int> t;
    Segtree() {
        t.assign(4 * N, INF);
    }

    int combine(const int& x, const int& y) {
        return (x < y ? x : y);
    }

    void update(int v, int s, int e, int pos, int val) {
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

    int get(int v, int s, int e, int l, int r) {
        if (e < l || s > r || l > r)
            return INF;
        if (l <= s && e <= r)
            return t[v];
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, r);
        int p2 = get(v << 1 | 1, mid + 1, e, l, r);
        return combine(p1, p2);
    }
} sgt;

int n, q;
int a[N];
int last[N];
int dp[N];
int up[N][K];
vector<int> primes[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i = 2; i < N; i++) {
        if (!primes[i].empty()) continue;
        for (int j = i; j < N; j += i) {
            primes[j].emplace_back(i);
        }
    }

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int k = 0; k < K; k++) {
        up[n + 1][k] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
        dp[i] = n + 1;
        int min_idx = n;
        for (int p : primes[a[i]]) {
            int rgt = (last[p] == 0 ? n : last[p] - 1);
            min_idx = min(min_idx, rgt);
            last[p] = i;
        }
        dp[i] = min(min_idx + 1, sgt.get(1, 1, n, i, min_idx));
        sgt.update(1, 1, n, i, dp[i]);
        up[i][0] = dp[i];
        for (int k = 1; k < K; k++) {
            up[i][k] = up[up[i][k - 1]][k - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = 1;
        for (int k = K - 1; k >= 0; k--) {
            if (up[l][k] > r) continue;
            l = up[l][k];
            ans += (1 << k);
        }
        cout << ans << '\n';
    }

    return 0;
}