#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    unordered_map<int, int> last;
    vector<vector<int>> a(m + 1);
    for (int i = 1; i <= m; i++) {
        int len;
        cin >> len;
        a[i].resize(len);
        for (int& x : a[i]) {
            cin >> x;
            last[x] = i;
        }
    }
    vector<int> ans;
    for (int i = 1; i <= m; i++) {
        int cur = -1;
        for (int x : a[i]) {
            if (last[x] == i) {
                cur = x;
                break;
            }
        }
        if (cur == -1) {
            cout << -1 << '\n';
            return;
        }
        ans.emplace_back(cur);
    }
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