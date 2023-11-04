#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    deque<int> vals(m);
    iota(vals.begin(), vals.end(), 0);
    vals.emplace_back(vals.front());
    vals.pop_front();
    deque<int> cur = vals;
    vector<vector<int>> ans(n, vector<int>(m));
    int cycle = m - 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = cur[j];
        }
        cycle--;
        if (cycle < 0) {
            cycle = m - 2;
            cur = vals;
        } else {
            cur.emplace_back(cur.front());
            cur.pop_front();
        }
    }
    vector<int> v(m);
    for (int j = 0; j < m; j++) {
        set<int> st;
        for (int i = 0; i < n; i++) {
            st.emplace(ans[i][j]);
        }
        while (st.count(v[j])) ++v[j];
    }
    set<int> st(v.begin(), v.end());
    int res = 0;
    while (st.count(res)) ++res;
    cout << res << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
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