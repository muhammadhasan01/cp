#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<bool> exist(n);
    vector<int> cnt(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            string b;
            cin >> b;
            if (a[j] == b) {
                exist[j] = true;
                cnt[i]++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!exist[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    int mx = *max_element(cnt.begin(), cnt.end());
    int ans = n + 2 * (n - mx);
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