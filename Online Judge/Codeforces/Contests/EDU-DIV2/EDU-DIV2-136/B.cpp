#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    vector<int> ans(n);
    ans[0] = d[0];
    for (int i = 1; i < n; i++) {
        if (d[i] == 0) {
            ans[i] = ans[i - 1];
            continue;
        }
        if (ans[i - 1] >= d[i]) {
            cout << -1 << '\n';
            return;
        }
        ans[i] = ans[i - 1] + d[i];
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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