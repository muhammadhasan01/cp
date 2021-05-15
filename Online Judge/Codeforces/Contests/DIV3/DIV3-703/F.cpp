#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> v;
    for (auto& e : mp) {
        v.emplace_back(e.second);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    int sz = v.size();
    for (int len = 1; len <= n; len++) {
        int pos = lower_bound(v.begin(), v.end(), len) - v.begin();
        if (pos >= sz) continue;
        ans = max(ans, len * (sz - pos));
    }
    cout << n - ans << '\n';
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