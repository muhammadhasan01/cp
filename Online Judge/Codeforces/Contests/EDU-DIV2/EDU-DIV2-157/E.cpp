#include <bits/stdc++.h>

using namespace std;

const int K = 3;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }
    int m;
    cin >> m;
    vector<pair<int, int>> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i].second;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<pair<int, int>> sa(n);
    for (int i = n - 1; i >= 0; i--) {
        sa[i] = make_pair(a[i].second, i);
        if (i != n - 1) {
            sa[i] = max(sa[i], sa[i + 1]);
        }
    }
    vector<pair<int, int>> sb(m);
    for (int i = m - 1; i >= 0; i--) {
        sb[i] = make_pair(b[i].second, i);
        if (i != m - 1) {
            sb[i] = max(sb[i], sb[i + 1]);
        }
    }
    int nodes = n + m;
    vector<int> p(nodes, -1);
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (b[mid].first > a[i].second) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at != -1) {
            p[i] = n + sb[at].second;
        }
    }
    for (int i = 0; i < m; i++) {
        int l = 0, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid].first > b[i].second) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at != -1) {
            p[i + n] = sa[at].second;
        }
    }
    vector<int> ans(nodes, -1);
    vector<bool> vis(nodes);
    for (int u = 0; u < n; u++) {
        if (ans[u] != -1) {
            continue;
        }
        int res = -1;
        stack<int> st;
        int x = u;
        st.emplace(x);
        vis[x] = true;
        while (true) {
            if (p[x] == -1) {
                res = (x < n ? 0 : 2);
                break;
            }
            x = p[x];
            if (ans[x] != -1) {
                res = ans[x];
                break;
            }
            if (vis[x]) {
                res = 1;
                break;
            }
            vis[x] = true;
            st.emplace(x);
        }
        while (!st.empty()) {
            ans[st.top()] = res;
            st.pop();
        }
    }
    vector<int> cnt(K);
    for (int u = 0; u < n; u++) {
        cnt[ans[u]]++;
    }
    for (int i = 0; i < K; i++) {
        cout << cnt[i] << " \n"[i == K - 1];
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