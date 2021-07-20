#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    vector<vector<int>> adj(n), radj(n);
    vector<int> deg(n);
    vector<int> pos(n);
    iota(pos.begin(), pos.end(), 0);
    for (int it = 0; it < 2; it++) {
        stack<int> st;
        for (int i : pos) {
            while (!st.empty() && h[st.top()] <= h[i]) {
                st.pop();
            }
            if (!st.empty()) {
                int j = st.top();
                adj[j].emplace_back(i);
                radj[i].emplace_back(j);
                deg[i]++;
            }
            st.emplace(i);
        }
        reverse(pos.begin(), pos.end());
    }
    queue<int> q;
    for (int u = 0; u < n; u++) {
        if (deg[u] == 0) {
            q.emplace(u);
        }
    }
    int m = 5;
    vector<int> bit(m);
    auto add = [&](int x, int val) -> void {
        for ( ; x < m; x += x & -x) {
            bit[x] += val;
        }
    };
    auto get = [&](int x) -> int {
        int ret = 0;
        for ( ; x > 0; x -= x & -x) {
            ret += bit[x];
        }
        return ret;
    };
    vector<int> ans(n);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        set<int> vals;
        for (int v : radj[u]) {
            vals.emplace(ans[v]);
        }
        for (int x : vals) {
            add(x, 1);
        }
        int l = 1, r = m - 1, at = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (get(mid) == mid) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        ans[u] = at + 1;
        for (int x : vals) {
            add(x, -1);
        }
        for (int v : adj[u]) {
            if (--deg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("tour.in", "r", stdin);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}