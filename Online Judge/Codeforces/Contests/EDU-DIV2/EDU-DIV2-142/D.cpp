#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        vector<int> pos(m + 1);
        for (int j = 0; j < m; j++) {
            pos[a[i][j]] = j + 1;
        }
        vector<int> res(m);
        for (int j = 1; j <= m; j++) {
            res[j - 1] = pos[j];
        }
        vector<int> cur;
        for (int j = 0; j < m; j++) {
            cur.emplace_back(res[j]);
            st.emplace(cur);
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        vector<int> cur;
        for (int j = 0; j < m; j++) {
            cur.emplace_back(a[i][j]);
            if (st.find(cur) == st.end()) {
                break;
            }
            ans[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
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