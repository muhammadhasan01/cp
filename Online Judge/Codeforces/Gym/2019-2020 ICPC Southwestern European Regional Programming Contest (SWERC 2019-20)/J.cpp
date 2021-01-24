// author : donbasta
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 1e9 + 7;
const int N = 1e6;

int n;
int t[4 * N + 5];
int ar[N + 5];
vector<int> pos[N + 5];
ll fc[2 * N + 5], ifc[2 * N + 5];

ll fpow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

ll inv(ll a) {
    return fpow(a, MOD - 2);
}

void build(int v, int s, int e) {
    if (s == e) {
        t[v] = ar[s];
        return;
    }
    int mid = (s + e) >> 1;
    build(v << 1, s, mid);
    build(v << 1 | 1, mid + 1, e);
    t[v] = min(t[v << 1], t[v << 1 | 1]);
}

int queryMin(int v, int s, int e, int l, int r) {
    if (s == l && e == r) {
        return t[v];
    }
    int mid = (s + e) >> 1;
    if (l > mid) return queryMin(v << 1 | 1, mid + 1, e, l, r);
    else if (r <= mid) return queryMin(v << 1, s, mid, l, r);
    return min(queryMin(v << 1, s, mid, l, mid), queryMin(v << 1 | 1, mid + 1, e, mid + 1, r));
}

void init_fac() {
    fc[0] = 1;
    for (int i = 1; i <= 2 * N; i++) {
        fc[i] = fc[i - 1] * i % MOD;
    }
    ifc[2 * N] = inv(fc[2 * N]);
    for (int i = 2 * N - 1; i >= 0; i--) {
        ifc[i] = ifc[i + 1] * (i + 1) % MOD;
    }
}

ll catalan(ll x) {
    ll ret = inv(x + 1);
    ret = ret * fc[x * 2] % MOD;
    ret = ret * ifc[x] % MOD;
    ret = ret * ifc[x] % MOD;
    return ret;
}

ll rec(int l, int r) {
    if (l >= r) return 1;
    int mn = queryMin(1, 1, n, l, r);
    int sz = (int)pos[mn].size();
    int kanan = upper_bound(pos[mn].begin(), pos[mn].end(), r) - pos[mn].begin(); 
    int kiri = lower_bound(pos[mn].begin(), pos[mn].end(), l) - pos[mn].begin();
    int cnt = kanan - kiri;
    assert(cnt > 0);
    ll ret = catalan(cnt);
    ret = ret * rec(l, pos[mn][kiri] - 1) % MOD;
    for (int i = kiri; i < kanan - 1; i++) {
        ret = ret * rec(pos[mn][i] + 1, pos[mn][i + 1] - 1) % MOD;
    }
    ret = ret * rec(pos[mn][kanan - 1] + 1, r) % MOD;
    return ret;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        pos[ar[i]].emplace_back(i);
    }
    if (n == 0) {
        cout << 1 << '\n';
        return;
    }
    build(1, 1, n);
    ll ans = rec(1, n);
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    init_fac();

    int TC = 1;
    for(int i = 1; i <= TC; i++) {
        solve();
    }
  
    return 0;
}