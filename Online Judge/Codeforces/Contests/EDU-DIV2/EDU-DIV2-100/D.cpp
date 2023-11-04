#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> others;
    for (int val = 1; val <= 2 * n; val++) {
        if (binary_search(b.begin(), b.end(), val)) {
            continue;
        }
        others.emplace_back(val);
    }
    int m = others.size();
    int L = n + 1, R = -1;
    {
        auto can = [&](int k) -> bool {
            for (int i = k - 1, j = m - 1; i >= 0; i--, j--) {
                if (j < 0 || others[j] < b[i]) {
                    return false;
                }
            }
            return true;
        };

        int l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                l = mid + 1;
                R = mid;
            } else {
                r = mid - 1;
            }
        }
    }
    {

        auto can = [&](int k) -> bool {
            for (int i = k, j = 0; i < n; i++, j++) {
                if (j >= m || others[j] > b[i]) {
                    return false;
                }
            }
            return true;
        };
        
        int l = 0, r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(mid)) {
                r = mid - 1;
                L = mid;
            } else {
                l = mid + 1;
            }
        }
    }
    if (L > R) {
        cout << 0 << '\n';
        return;
    }
    cout << R - L + 1 << '\n';
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