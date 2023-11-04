#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = make_pair(x, i);
        st.emplace(i, x);
    }
    sort(a.begin(), a.end());
    long long ans = 0;
    for (auto [val, pos] : a) {
        auto it = st.find(make_pair(pos, val));
        if (it == st.end()) {
            continue;
        }
        while (next(it, 1) != st.end() && next(it, 1)->second <= it->second) {
            ans += it->second;
            st.erase(next(it, 1));
        }
        while (it != st.begin() && prev(it, 1)->second <= it->second) {
            ans += it->second;
            st.erase(prev(it, 1));
        }
    }
    cout << ans << '\n';

    
    return 0;
}