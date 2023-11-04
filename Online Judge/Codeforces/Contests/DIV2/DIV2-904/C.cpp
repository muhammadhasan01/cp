#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> p(n);
    for (auto& [s, e] : p) {
        cin >> s >> e;
    }

    auto getMax = [&](vector<pair<int, int>>& P) {
        vector<pair<int, int>> events;
        for (auto& [s, e] : P) {
            events.emplace_back(s, 1);
            events.emplace_back(e + 1, -1);
        }
        sort(events.begin(), events.end());
        int cur = 0;
        int mx = 0;
        for (auto& [_, add] : events) {
            cur += add;
            mx = max(mx, cur);
        }
        return mx;
    };

    int ans = 0;
    {
        vector<pair<int, int>> p1;
        for (auto& [s, e] : p) {
            if (s <= 1 && 1 <= e) {
                continue;
            }
            p1.emplace_back(s, e);
        }
        ans = max(ans, getMax(p1));
    }
    {
        vector<pair<int, int>> pm;
        for (auto& [s, e] : p) {
            if (s <= m && m <= e) {
                continue;
            }
            pm.emplace_back(s, e);
        }
        ans = max(ans, getMax(pm));
    }
    cout << ans << '\n';
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