#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    sort(k.begin(), k.end());

    auto query = [&](long long a, long long b, long long c) -> void {
        long long cur = 4LL * a * c;
        if (cur <= 0) {
            cout << "NO" << '\n';
            return;
        }
        long long l = -INF, r = b, at = b;
        while (l <= r) {
            long long mid = (l + r) >> 1LL;
            long long val = (mid - b) * (mid - b);
            if (val < cur) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        auto it = lower_bound(k.begin(), k.end(), at);
        if (it == k.end()) {
            cout << "NO" << '\n';
            return;
        }
        long long val = (*it - b) * (*it - b);
        if (val >= cur) {
            cout << "NO" << '\n';
            return;
        }
        cout << "YES" << '\n';
        cout << *it << '\n'; 
    };

    while (m--) {
        long long a, b, c;
        cin >> a >> b >> c;
        query(a, b, c);
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}