#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    a[0] = a[n + 1] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = max(a[i - 1], a[i + 1]);
        if (cur >= a[i]) continue;
        ans += a[i] - cur;
        a[i] = cur;
    }
    for (int i = 1; i <= n + 1; i++) {
        ans += abs(a[i] - a[i - 1]);
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