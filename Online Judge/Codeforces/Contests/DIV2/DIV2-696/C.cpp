#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m);
    map<int, int> freq;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    sort(a.begin(), a.end());
    for (int pos = 0; pos < m - 1; pos++) {
        vector<pair<int, int>> ans;
        map<int, int> mp = freq;
        mp[a[m - 1]]--;
        mp[a[pos]]--;
        ans.emplace_back(a[m - 1], a[pos]);
        int mx = a[m - 1];
        bool flag = false;
        for (int i = m - 2; i >= 0; i--) {
            if (mp[a[i]] == 0) {
                continue;
            }
            int cur = mx - a[i];
            if (mp[cur] == 0) {
                flag = true;
                break;
            }
            mp[a[i]]--;
            mp[cur]--;
            ans.emplace_back(a[i], cur);
            mx = max(a[i], cur);
        }
        if ((int) ans.size() != n) {
            continue;
        }
        if (flag) {
            continue;
        }
        cout << "YES" << '\n';
        cout << a[pos] + a[m - 1] << '\n';
        for (auto& [u, v] : ans) {
            cout << u << ' ' << v << '\n';
        }
        return;
    }
    cout << "NO" << '\n';
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