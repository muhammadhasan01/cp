#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<pair<int, int>> res;
    int cur = s[0], cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cur == s[i]) {
            ++cnt;
        } else {
            res.emplace_back(cur, cnt);
            cur = s[i];
            cnt = 1;
        }
    }
    res.emplace_back(cur, cnt);
    vector<int> ans(n);
    int l = 0;
    int iter = 0;
    for (auto [val, c] : res) {
        if (c == 1) {
            cout << -1 << '\n';
            return;
        }
        for (int i = 1; i < c; i++) {
            ans[l + i] = ++iter;
        }
        ans[l] = ++iter;
        l += c;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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