#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[i] = make_pair(v[i], i);
    }
    sort(a.rbegin(), a.rend());
    vector<bool> vis(n);
    vector<int> ans(n);
    int len = 0;
    for (int i = 0; i < n; i++) {
        auto& [_, id] = a[i];
        for (int j = id; j < n; j++) {
            if (vis[j]) {
                break;
            }
            vis[j] = true;
            ans[len++] = v[j];
        }
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