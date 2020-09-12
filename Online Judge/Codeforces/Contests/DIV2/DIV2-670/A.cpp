#include <bits/stdc++.h>

using namespace std;

int MEX(const vector<int>& v) {
    vector<int> cnt(105);
    for (auto& e : v)
        cnt[e] = 1;
    for (int i = 0; i < 105; i++) {
        if (cnt[i] == 0)
            return i;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        vector<vector<int>> v_temp(2);
        vector<bool> vis(n);
        for (int j = 0; j < n; j++) {
            if ((int) v_temp[0].size() == i) break;
            if (v_temp[0].empty()) {
                v_temp[0].emplace_back(v[j]);
                vis[j] = 1;
            } else if (v_temp[0].back() != v[j]) {
                v_temp[0].emplace_back(v[j]);
                vis[j] = 1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (vis[j]) continue;
            v_temp[1].emplace_back(v[j]);
        }
        int res = 0;
        for (int it = 0; it < 2; it++)
            res += MEX(v_temp[it]);
        ans = max(ans, res);
    }
    cout << ans << '\n';
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