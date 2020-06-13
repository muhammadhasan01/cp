#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e6;

int tc;
int n, x;
int a[N], pre[N], t[4 * N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = INF;
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

void update(int v, int s, int e, int pos, int val) {
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

int get(int v, int s, int e, int l, int r) {
    if (e < l || s > r || l > r) return INF;
    if (l <= s && e <= r) return t[v];
    int mid = (s + e) >> 1;
    int p1 = get(v << 1, s, mid, l, r);
    int p2 = get(v << 1 | 1, mid + 1, e, l, r);
    return min(p1, p2);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = (a[i] + pre[i - 1]) % x;
        }
        build(1, 0, x - 1);
        vector<int> dp(x + 5);
        for (int i = 0; i < x; i++) {
            dp[i] = INF;
        }
        dp[0] = 0;
        update(1, 0, x - 1, 0, 0);
        for (int i = 1; i <= n; i++) {
            int k = pre[i];
            int p1 = get(1, 0, x - 1, 0, k - 1);
            int p2 = get(1, 0, x - 1, k + 1, x - 1);
            int pos = min(p1, p2);
            ans = max(ans, i - pos);
            if (dp[k] == INF) {
                dp[k] = i;
                update(1, 0, x - 1, k, dp[k]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}