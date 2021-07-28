#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

template<int MAXN, typename T, const T& TERM>
struct Segtree {
    vector<T> t;
    Segtree() {
        t.assign(4 * MAXN, TERM);
    }

    T combine(const T& x, const T& y) {
        return (x + y) % M;
    }

    void update(int v, int s, int e, int pos, T val) {
        if (s == e && s == pos) {
            t[v] = (val % M);
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

const int N = 2e5 + 5;
const int TERM = 0;

int n;
int x[N], y[N], s[N];
int dp[N];
Segtree<N, int, TERM> sgt;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> s[i];
    }
    x[n + 1] = x[n] + 1;
    s[n + 1] = 1;
    auto get = [&](int pos) -> int {
        int l = 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (x[mid] > pos) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        return at;
    };
    for (int i = 1; i <= n; i++) {
        int j = get(y[i]);
        dp[i] = (x[i] - y[i]) % M;
        if (j < i) {
            dp[i] = (dp[i] + sgt.get(1, 1, n, j, i - 1)) % M;
        }
        sgt.update(1, 1, n, i, dp[i]);
    }
    int ans = 0;
    for (int i = 1, last = 0; i <= n + 1; i++) {
        if (s[i] == 0) {
            continue;
        }
        ans = (ans + (x[i] - last) % M) % M;
        ans = (ans + dp[i]) % M;
        last = x[i];
    }
    cout << ans % M << '\n';

    return 0;
}