#include <bits/stdc++.h>

using namespace std;

void solve() {
    string L, R;
    cin >> L >> R;
    while (L.size() < R.size()) {
        L = "0" + L;
    }
    int n = L.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(L[i] - R[i]);
    }
    for (int i = 0; i < n; i++) {
        if (L[i] == R[i]) {
            continue;
        }
        int res = abs(L[i] - R[i]);
        for (int j = i + 1; j < n; j++) {
            res += 9;
        }
        ans = max(ans, res);
        break;
    }
    cout << ans << '\n';
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