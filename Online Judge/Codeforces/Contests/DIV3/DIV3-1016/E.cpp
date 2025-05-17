#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto can = [&](int x) -> bool {
        if (x == 0) {
            return true;
        }
        int seg = 0;
        vector<int> freq(x, 0);
        int missing = x;
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                if (freq[a[i]] == 0) {
                    missing--;
                }
                freq[a[i]]++;
            }
            if (missing == 0) {
                seg++;
                freq.assign(x, 0);
                missing = x;
            }
        }
        return seg >= k;
    };

    int l = 0, r = n + 2, ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (can(mid)) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}
