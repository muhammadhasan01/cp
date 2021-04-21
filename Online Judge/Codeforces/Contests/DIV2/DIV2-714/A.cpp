#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int maxi = (n % 2 == 0 ? n / 2 - 1 : n / 2);
    if (k > maxi) {
        cout << -1 << '\n';
        return;
    }
    int cur = (n + 1) / 2;
    vector<int> ans;
    vector<int> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans.emplace_back(i);
        if (k > 0) {
            ans.emplace_back(i + cur);
            vis[i + cur] = 1;
            --k;
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

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}