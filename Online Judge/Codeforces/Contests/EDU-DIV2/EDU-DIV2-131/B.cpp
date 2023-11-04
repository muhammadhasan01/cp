#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> vis(n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        int x = i;
        while (x <= n) {
            vis[x] = true;
            ans.emplace_back(x);
            x = x + x;
        }
    }
    cout << 2 << '\n';
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