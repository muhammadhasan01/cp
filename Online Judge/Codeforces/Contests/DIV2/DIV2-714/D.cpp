#include <bits/stdc++.h>

using namespace std;

const int MAXN = (1 << 20);
const int MAXLOG = 20;
const int N = 2e5 + 5;
const int INF = 2e9;

struct SegtreeLazy {
    vector<int> t;
    vector<int> lazy;
    SegtreeLazy() {
        t.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }

    int combine(const int& x, const int& y) {
        return (x < y ? x : y);
    }

    void build(int v, int s, int e, vector<int>& a) {
        lazy[v] = INF;
        if (s == e) {
            t[v] = a[s];
            return;
        }
        int mid = (s + e) >> 1;
        build(v << 1, s, mid, a);
        build(v << 1 | 1, mid + 1, e, a);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    void push(int v, int s, int e) {
        if (lazy[v] == INF || s == e) return;
        t[v << 1] = min(t[v << 1], lazy[v]);
        t[v << 1 | 1] = min(t[v << 1 | 1], lazy[v]);
        lazy[v << 1] = min(lazy[v << 1], lazy[v]);
        lazy[v << 1 | 1] = min(lazy[v << 1 | 1], lazy[v]);
        lazy[v] = INF;
    }

    void update(int v, int s, int e, int l, int r, int val) {
        if (l > r) return;
        if (l == s && e == r) {
            t[v] = min(t[v], val);
            lazy[v] = min(lazy[v], val);
            return;
        }
        push(v, s, e);
        int mid = (s + e) >> 1;
        update(v << 1, s, mid, l, min(r, mid), val);
        update(v << 1 | 1, mid + 1, e, max(l, mid + 1), r, val);
        t[v] = combine(t[v << 1], t[v << 1 | 1]);
    }

    int get(int v, int s, int e, int l, int r) {
        if (l > r)
            return INF;
        if (l <= s && e <= r)
            return t[v];
        push(v, s, e);
        int mid = (s + e) >> 1;
        int p1 = get(v << 1, s, mid, l, min(r, mid));
        int p2 = get(v << 1 | 1, mid + 1, e, max(l, mid + 1), r);
        return combine(p1, p2);
    }
} sgt;

struct sparse_table {
	int dp[MAXN][MAXLOG];
	int prec_lg2[MAXN], n;

	sparse_table() {
        memset(dp, 0, sizeof(dp));
        memset(prec_lg2, 0, sizeof(prec_lg2));
        n = 0;
    }

	void init(vector<int> &a) {
		n = a.size();
		for (int i = 2; i < 2 * n; i++) prec_lg2[i] = prec_lg2[i >> 1] + 1;
		for (int i = 0; i < n; i++) dp[i][0] = a[i];
        for (int i = n; i < 2 * n; i++) dp[i][0] = 0;
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i < n; i++)
				dp[i][j] = __gcd(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r) {
		int k = prec_lg2[r - l + 1];
		return __gcd(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
} sp;

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> v(n, p);
    sgt.build(1, 0, n - 1, v);
    sp.init(a);
    for (int i = 0; i < n; i++) {
        {
            int l = i + 1, r = n - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[i] == sp.query(i, mid)) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (at != -1) {
                sgt.update(1, 0, n - 1, i + 1, at, a[i]);
            }
        }
        {
            int l = 0, r = i - 1, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[i] == sp.query(mid, i)) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (at != -1) {
                sgt.update(1, 0, n - 1, at + 1, i, a[i]);
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int res = sgt.get(1, 0, n - 1, i, i);
        ans += res;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}