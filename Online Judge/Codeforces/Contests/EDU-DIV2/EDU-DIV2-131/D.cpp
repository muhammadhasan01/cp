#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> in(n + 1);
    vector<int> tout(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        int L = -1, R = -1;
        if (x == 0) {
            L = i + 1;
            R = n;
        } else {
            L = i / (x + 1) + 1;
            R = i / x;
        }
        in[L].emplace_back(i);
        tout[i] = R;
    }
    set<pair<int, int>> st;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j : in[i]) {
            st.emplace(tout[j], j);
        }
        ans[st.begin()->second] = i;
        st.erase(st.begin());
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