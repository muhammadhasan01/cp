#include <bits/stdc++.h>

using namespace std;

const int K = 2;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x].emplace_back(i);
    }
    vector<vector<int>> ans(K, vector<int>(n, -1));
    vector<pair<int, int>> st;
    for (int x = n; x >= 1; x--) {
        int len = (int) pos[x].size();
        if (len > K) {
            cout << "NO" << '\n';
            return;
        }
        if (len == K) {
            int l = pos[x][0], r = pos[x][1];
            ans[0][l] = x;
            ans[1][r] = x;
            st.emplace_back(l, r);
            continue;
        }
        if (len == 1) {
            int at = pos[x][0];
            ans[0][at] = x;
            ans[1][at] = x;
            continue;
        }
        if (st.empty()) {
            cout << "NO" << '\n';
            return;
        }
        auto [l, r] = st.back();
        st.pop_back();
        ans[1][l] = x;
        ans[0][r] = x;
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == -1) {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " \n"[j == n - 1];
        }
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