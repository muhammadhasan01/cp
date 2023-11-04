#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> k(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    vector<long long> h(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    long long ans = 0;
    vector<bool> skip(n + 1);
    for (int i = n; i >= 1; i--) {
        if (skip[i]) {
            continue;
        }
        long long mostLeft = k[i] - h[i] + 1;
        int at = i;
        for (int j = i - 1; j >= 1; j--) {
            if (k[j] < mostLeft) {
                at = j;
                break;
            }
            skip[j] = true;
            mostLeft = min(mostLeft, k[j] - h[j] + 1);
        }
        long long res = k[i] - mostLeft + 1;
        ans += res * (res + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }

    return 0;
}