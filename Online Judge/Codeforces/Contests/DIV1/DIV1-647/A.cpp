#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int INF = 2e9;

int n, m;
vector<int> g[N];
pair<int, int> q[N];
int t[N], ans[N];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        q[i] = make_pair(t[i], i);
    }
    sort(q + 1, q + 1 + n);
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (q[i].first == 1 + cur) {
            cur = q[i].first;
        } else if (q[i].first > 1 + cur) {
            dismiss();
        }
        int u = q[i].second;
        int maxi = 1;
        set<int> st;
        for (auto v : g[u]) st.insert(ans[v]);
        for (auto& e : st) {
            if (maxi < e) break;
            maxi = e + 1;
        }
        ans[u] = maxi;
        if (ans[u] != t[u]) dismiss();
    }
    for (int i = 1; i <= n; i++) {
        cout << q[i].second << (i == n ? '\n' : ' ');
    }

    return 0;
}