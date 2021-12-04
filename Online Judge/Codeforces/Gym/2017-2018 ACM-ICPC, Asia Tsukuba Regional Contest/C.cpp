#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<pair<long long, long long>> p(n); // start, period
    p[0] = make_pair(h[0], h[0]);
    for (int i = 1; i < n; i++) {
        auto& [x, y] = p[i - 1];
        p[i] = make_pair(x + h[i], max(h[i], y));
    }
    for (int i = 0; i < n; i++) {
        auto& [x, y] = p[i];
        if (x > t) {
            cout << 1 << '\n';
            continue;
        }
        cout << 2 + (t - x) / y << '\n';
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