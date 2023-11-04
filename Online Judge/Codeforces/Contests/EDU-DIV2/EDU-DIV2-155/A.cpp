#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (auto& [s, e] : p) {
        cin >> s >> e;
    }
    int S = p[0].first;
    int E = p[0].second;
    for (int i = 1; i < n; i++) {
        auto [s, e] = p[i];
        if (S > s) {
            continue;
        }
        if (e >= E) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << S << '\n';
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