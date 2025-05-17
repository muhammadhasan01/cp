#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> suf(n + 2);
    vector<bool> vis(n + 1);
    for (int i = n, res = 0; i >= 1; i--) {
        vis[a[i]] = true;
        while (vis[res]) {
            ++res;
        }
        suf[i] = res;
    }
    fill(vis.begin(), vis.end(), false);
    vector<int> ans;
    for (int i = 1, res = 0, pos = 1; i <= n; i++) {
        vis[a[i]] = true;
        while (vis[res]) {
            ++res;
        }
        if (suf[pos] == res) {
            pos = i + 1;
            ans.emplace_back(res);
            for (int j = 0; j < res; j++) {
                vis[j] = false;
            }
            res = 0;
        }
    }
    int m = (int) ans.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
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