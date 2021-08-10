#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long INF = 1e18;

int n;
int a[N];
long long pre[N], suf[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i];
    }
    suf[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    long double ans = -INF;
    for (int i = 1; i < n; i++) {
        long double x = (long double) pre[i] / i;
        long double y = (long double) suf[i + 1] / (n - i);
        ans = max(ans, x + y);
    }
    cout << fixed << setprecision(12) << ans << '\n';
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