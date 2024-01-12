#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> e(n);
    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; i++) {
        events.emplace_back(s[i], 0, i);
        events.emplace_back(e[i], 2, i);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        events.emplace_back(x, 1, i);
    }
    sort(events.begin(), events.end());
    int len = 0;
    vector<int> ans(m);
    for (auto [t, tp, i] : events) {
        if (tp == 0) {
            ++len;
        } else if (tp == 1) {
            ans[i] = len;
        } else if (tp == 2) {
            --len;
        }
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