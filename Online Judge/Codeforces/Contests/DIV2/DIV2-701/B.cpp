#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, k, q;
int a[N];
long long pre[N];

void solve() {
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = 1; a[n + 1] = k;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i + 1] - a[i - 1] - 2;
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << k - 1 << '\n';
            continue;
        }
        long long ans = a[l + 1] - 2;
        ans += (k - a[r - 1] - 1);
        if (r - l > 1) ans += pre[r - 1] - pre[l];
        cout << ans << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}