#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> st;
    for (int x : a) {
        if (st.empty() || st.back().first != x) {
            st.emplace_back(x, 1);
            continue;
        }
        auto [_, cnt] = st.back();
        st.pop_back();
        st.emplace_back(x, cnt + 1);
    }
    long long ans = 0;
    int cur = 0;
    for (auto [_, cnt] : st) {
        if (cnt >= 3) {
            ans += 1LL * cnt * (cnt - 1) * (cnt - 2) / 6LL;
        }
        if (cnt >= 2) {
            ans += 1LL * cur * cnt * (cnt - 1) / 2;
        }
        cur += cnt;
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