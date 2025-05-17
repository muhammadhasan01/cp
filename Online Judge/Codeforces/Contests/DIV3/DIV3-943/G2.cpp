#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    z[0] = n;
    return z;
}

void solve() {
    int n;
    cin >> n;
    int l, r;
    cin >> l >> r;
    string s;
    cin >> s;
    vector<int> z = z_function(s);
    vector<pair<int, int>> p(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        p[i] = {z[i], i};
        st.emplace(i);
    }
    sort(p.rbegin(), p.rend());
    vector<int> dp(n + 1);
    for (int len = 1; len <= n; len++) {
        while (!p.empty() && p.back().first < len) {
            st.erase(p.back().second);
            p.pop_back();
        }
        while (*prev(st.end()) + len - 1 >= n) {
            st.erase(prev(st.end()));
        }
        int pos = *st.begin();
        int cnt = 1;
        while (1) {
            auto it = st.upper_bound(pos + len - 1);
            if (it == st.end()) {
                break;
            }
            pos = *it;
            ++cnt;
        }
        dp[len] = cnt;
    }
    vector<int> ans(n + 1);
    for (int i = n, j = 0; i >= 1; i--) {
        while (j + 1 <= n && dp[j + 1] >= i) {
            j++;
        }
        ans[i] = j;
    }
    for (int i = l; i <= r; i++) {
        cout << ans[i] << " \n"[i == r];
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