#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        int x = min(a[i], a[i + 1]);
        int y = max(a[i], a[i + 1]);
        int res = 0;
        while (y > 2 * x) {
            x = x + x;
            res++;
        }
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