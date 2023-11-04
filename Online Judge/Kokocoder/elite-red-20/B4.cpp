#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a[i] = make_pair(val, i);
    }
    sort(a.begin(), a.end(), [&](auto& lhs, auto& rhs) {
        if (lhs.first == rhs.first) {
            return lhs.second > rhs.second;
        }
        return lhs.first < rhs.first;
    });
    set<int> st;
    for (auto [_, pos] : a) {
        auto it = st.lower_bound(pos);
        if (it == st.end()) {
            st.emplace(pos);
            continue;
        }
        st.erase(it);
        st.emplace(pos);
    }
    cout << (int) st.size() << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}