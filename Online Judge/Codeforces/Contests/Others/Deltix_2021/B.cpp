#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
    }
    vector<tuple<int, int, int>> ans;
    for (int i = 1; i <= n; i += 2) {
        ans.emplace_back(2, i, i + 1);
        ans.emplace_back(1, i, i + 1);
        ans.emplace_back(2, i, i + 1);
        ans.emplace_back(1, i, i + 1);
        ans.emplace_back(2, i, i + 1);
        ans.emplace_back(1, i, i + 1);
    }
    cout << ans.size() << '\n';
    for (auto& [t, i, j] : ans) {
        cout << t << ' ' << i << ' ' << j << '\n';
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