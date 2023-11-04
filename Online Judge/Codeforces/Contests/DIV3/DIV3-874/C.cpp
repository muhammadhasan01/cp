#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<set<int>> st(K);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[a[i] & 1].emplace(a[i]);
    }

    auto can = [&](int bit) -> bool {
        for (int i = 0; i < n; i++) {
            int cur = a[i] & 1;
            if (cur == bit) {
                continue;
            }
            if (st[1].empty()) {
                return false;
            }
            auto it = st[1].lower_bound(a[i]);
            if (it == st[1].begin()) {
                return false;
            }
        }
        return true;
    };

    for (int bit = 0; bit < K; bit++) {
        if (can(bit)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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