#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (k >= 3) {
        cout << 0 << '\n';
        return;
    }
    sort(a.begin(), a.end());
    long long ans = a[0];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long cur = abs(a[j] - a[i]); 
            ans = min(ans, cur);
            if (k == 2) {
                int pos = upper_bound(a.begin(), a.end(), cur) - a.begin();
                if (pos < n) {
                    ans = min(ans, abs(a[pos] - cur));
                }
                if (pos - 1 >= 0) {
                    ans = min(ans, abs(a[pos - 1] - cur));
                }
            }
        }
    }
    cout << ans << '\n';
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