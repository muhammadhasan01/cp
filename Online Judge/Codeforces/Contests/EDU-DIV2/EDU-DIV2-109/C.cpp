#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    vector<char> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        p[i] = make_pair(x[i], i);
    }
    sort(p.begin(), p.end());
    vector<int> ans(n, -1);
    vector<deque<int>> dq(2);
    for (int i = 0; i < n; i++) {
        auto [val, id] = p[i];
        deque<int>& cur = dq[val % 2];
        if (cur.empty()) {
            cur.emplace_back(id);
        } else {
            if (c[id] == 'L') {
                int pos = cur.back();
                cur.pop_back();
                int res = (x[id] - x[pos]) / 2;
                if (c[pos] == 'L') {
                    res += x[pos];
                }
                ans[id] = ans[pos] = res;
            } else if (c[id] == 'R') {
                cur.emplace_back(id);
            }
        }
    }
    for (int it = 0; it < 2; it++) {
        while ((int) dq[it].size() > 1) {
            int id = dq[it].back();
            dq[it].pop_back();
            int pos = dq[it].back();
            dq[it].pop_back();
            int res = (x[id] - x[pos]) / 2 + (m - x[id]);
            if (c[pos] == 'L') {
                res += x[pos];
            }
            ans[pos] = ans[id] = res;
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