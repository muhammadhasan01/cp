#include <bits/stdc++.h>

using namespace std;

int get(vector<int>& v, vector<int>& w) {
    if (v.empty() || w.empty()) return 0;
    int n = v.size(), m = w.size();
    vector<int> suf(m + 5);
    for (int i = m - 1; i >= 0; i--) {
        suf[i] = suf[i + 1];
        if (binary_search(v.begin(), v.end(), w[i])) {
            suf[i]++;
        }
    }
    int ret = suf[0];
    for (int i = 0; i < m; i++) {
        int pos = upper_bound(v.begin(), v.end(), w[i]) - v.begin() - 1;
        if (pos < 0) continue;
        int len = pos + 1;
        int lft = w[i] - len + 1;
        int at = lower_bound(w.begin(), w.end(), lft) - w.begin();
        ret = max(ret, i - at + 1 + suf[i + 1]);
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(2);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v[(x < 0)].emplace_back(abs(x));
    }
    vector<vector<int>> w(2);
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        w[(x < 0)].emplace_back(abs(x));
    }
    reverse(v[1].begin(), v[1].end());
    reverse(w[1].begin(), w[1].end());
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        ans += get(v[i], w[i]);
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