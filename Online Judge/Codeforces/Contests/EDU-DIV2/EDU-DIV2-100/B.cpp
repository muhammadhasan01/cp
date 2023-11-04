#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += 1LL * a[i];
    }
    for (int it = 0; it < 2; it++) {
        vector<int> ans(n);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if ((i & 1) == (it & 1)) {
                ans[i] = a[i];
            } else {
                ans[i] = 1;
            }
            res += 1LL * abs(a[i] - ans[i]);
        }
        if (2LL * res <= sum) {
            for (int i = 0; i < n; i++) {
                cout << ans[i] << " \n"[i == n - 1];
            }
            return;
        }
    }
    assert(false);
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