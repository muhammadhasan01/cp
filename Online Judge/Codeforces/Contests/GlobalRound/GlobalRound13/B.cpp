#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int a[N];
long long u, v;

void solve() {
    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int maxi = 0;
    for (int i = 1; i < n; i++) {
        maxi = max(maxi, abs(a[i] - a[i + 1]));
    }
    if (maxi == 0) {
        cout << v + min(u, v) << '\n';
    } else if (maxi == 1) {
        cout << min(u, v) << '\n';
    } else {
        cout << 0 << '\n';
    }
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