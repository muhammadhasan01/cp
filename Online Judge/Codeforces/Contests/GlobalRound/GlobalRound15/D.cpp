#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int mask = 1; mask < (1 << n); mask++) {
        vector<int> bit;
        for (int i = 0; i < n; i++) {
            bool b = mask & (1 << i);
            if (b) {
                bit.emplace_back(i);
            }
        }
        int len = bit.size();
        for (int m = 0; m < (1 << len); m++) {
            int res = 0;
            for (int i = 0; i < len; i++) {
                bool b = m & (1 << i);
                if (b) {
                    res += a[bit[i]];
                } else {
                    res -= a[bit[i]];
                }
            }
            if (res == 0) {
                cout << "YES" << '\n';
                return;
            }
        }
    }
    cout << "NO" << '\n';
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