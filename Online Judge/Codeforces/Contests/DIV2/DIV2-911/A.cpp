#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<char, int>> st;
    for (char cc : s) {
        if (st.empty() || st.back().first != cc) {
            st.emplace_back(cc, 1);
            continue;
        }
        auto [c, cnt] = st.back();
        st.pop_back();
        st.emplace_back(c, cnt + 1);
    }
    int ans = 0;
    for (auto [cc, cnt] : st) {
        if (cc == '#') {
            continue;
        }
        if (cnt >= 3) {
            cout << 2 << '\n';
            return;
        }
        ans += cnt;
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