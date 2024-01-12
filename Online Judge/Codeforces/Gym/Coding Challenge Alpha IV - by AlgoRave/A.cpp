#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (st.empty() || st.back().first != x) {
            st.emplace_back(x, 1);
            continue;
        }
        auto [_, cnt] = st.back();
        st.pop_back();
        st.emplace_back(x, cnt + 1);
    }
    int ans = 0;
    for (auto [x, cnt] : st) {
        if (x == 7) {
            ans = max(ans, cnt);
        }
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