#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int k;
    cin >> k;
    for (int i = n - 2; i >= 0; i--) {
        c[i] = min(c[i], c[i + 1]);
    }
    int res = k;
    for (int i = 0; i < n; i++) {
        int val = (i == 0 ? c[i] : c[i] - c[i - 1]);
        if (val > 0) {
            res = min(res, k / val);
        }
        k -= res * val;
        cout << res << " \n"[i == n - 1];
    }
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