#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int M = 1e9 + 7;
long long pre[N], erp[N];
int n, m;

ll egcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0) {
        x = 0, y = 1;
        return b;
    }
    ll x1, y1;
    ll d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inv(ll a) {
    ll x1, y1;
    egcd(a, M, x1, y1);
    return (x1 % M + M) % M;
}

ll c(ll a, ll b) {
    if (b > a) return 0;
    if (b == 0 || a == b) return 1;
    ll ret = pre[a] * erp[b];
    ret %= M;
    ret *= erp[a - b];
    ret %= M;
    return (ret % M + M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    pre[0] = 1;
    for (int i = 1; i <= N - 5; i++) {
        pre[i] = i * pre[i - 1];
        pre[i] %= M;
    }
    for (int i = 1; i <= N - 5; i++) {
        erp[i] = inv(pre[i]);
    }

    long long ans = 0;
    for (int i = 0; i <= (n / 3); i++) {
        ll kali = 1;
        if (i & 1) {
            kali = -1;
        }
        ans += (kali) * (c(m + 1, i)) * (c(m + n - 3 * i, n - 3 * i));
        ans %= M;
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}
