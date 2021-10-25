#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<set<pair<int, int>>> in(n + 5), out(n + 5);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        in[l].emplace(r, i);
        out[r + 1].emplace(r, i);
    }
    vector<int> ans(n + 1, -1);
    set<pair<int, int>> st;
    for (int t = 1; t <= n; t++) {
        for (auto& [r, id] : out[t]) {
            st.erase(make_pair(r, id));
        }
        for (auto& [r, id] : in[t]) {
            st.emplace(r, id);
        }
        if (!st.empty()) {
            auto [r, id] = *st.begin();
            st.erase(st.begin());
            ans[t] = id + 1;
        }
    }
    if (*min_element(ans.begin() + 1, ans.end()) == -1) {
        cout << "impossible" << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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