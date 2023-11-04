#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    long long k;
    int q;
    cin >> n >> k >> q;
    vector<int> p(n);
    for (int u = 1; u < n; u++) {
        cin >> p[u];
        p[u]--;
    }
    vector<int> dp(n, 1);
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    for (int u = n - 1; u > 0; u--) {
        if (dp[u] + 1 > dp[p[u]]) {
            dp[p[u]] = dp[u] + 1;
            pos[p[u]] = u;
        }
    }
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int& i, int& j) {
        return dp[i] > dp[j];
    });
    vector<bool> vis(n);
    vector<int> ans(n, -1);
    int offset = 1;
    for (int u : ord) {
        if (vis[u]) {
            continue;
        }
        vector<int> path;
        for (int x = u; !vis[x]; x = pos[x]) {
            vis[x] = true;
            path.emplace_back(x);
        }
        int m = (int) path.size();
        for (int i = 0, l = offset, r = offset + m - 1, cur = m - 1; i < m; i++, cur--) {
            if (k >= cur) {
                k -= cur;
                ans[path[i]] = r--;
            } else {
                ans[path[i]] = l++;
            }
        }
        offset += m;
    }
    if (k > 0) {
        cout << "TIDAK" << '\n';
        return 0;
    }
    cout << "YA" << '\n';
    if (q == 1) {
        assert(*min_element(ans.begin(), ans.end()) != -1);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}