#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const ll inf = 1e18;
int n, m, s;
ll t[4 * N];
int cnt[N];

vector<ll> dp;
vector<pair<int,ll>> st[N];

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = dp[s];
    } else {
        int mid = (s + e) >> 1;
        build(2 * v, s, mid);
        build(2 * v + 1, mid + 1, e);
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

void update(int v, int s, int e, int pos, ll val) {
    if (s == e) {
        t[v] = val;
    } else {
        int mid = (s + e) >> 1;
        if (pos <= mid) {
            update(2 * v, s, mid, pos, val);
        } else {
            update(2 * v + 1, mid + 1, e, pos, val);
        }
        t[v] = min(t[2 * v], t[2 * v + 1]);
    }
}

ll get(int v, int s, int e, int l, int r) {
    if (s > r || e < l) {
        return inf;
    }

    if (l <= s && e <= r) return t[v];

    int mid = (s + e) >> 1;
    ll p1 = get(2 * v, s, mid, l, r);
    ll p2 = get(2 * v + 1, mid + 1, e, l, r);
    return min(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        cnt[l]++;
        cnt[r + 1]--;
    }


    for (int i = 1; i <= m; i++) {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        st[r].push_back({l, c});
    }

    dp.assign(s + 2, inf);
    dp[0] = 0;

    build(1, 0, s);

    for (int i = 1; i <= s; i++) {
        cnt[i] += cnt[i - 1];
        if (cnt[i] == 0) {
            dp[i] = min(dp[i], dp[i - 1]);
        }

        for (auto e : st[i]) {
            int l = e.first;
            ll c = e.second;
            ll g = get(1, 0, s, l - 1, i - 1);
            dp[i] = min(dp[i], g + c);
        }

        update(1, 0, s, i, dp[i]);
    }

    cout << dp[s] << '\n';

    return 0;
}
