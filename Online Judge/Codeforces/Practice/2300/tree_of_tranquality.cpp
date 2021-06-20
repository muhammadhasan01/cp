#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int M = 2 * N;

int n;
vector<int> adj[2][N];
int tin[M], tout[M], tim;
set<pair<int, int>> st;
int ans;

void init() {
    tim = 0, ans = 0;
    st.clear();
    for (int i = 1; i <= n; i++) {
        tin[i] = tout[i] = 0;
        adj[0][i].clear();
        adj[1][i].clear();
    }
}

int add(int u) {
    auto it = st.lower_bound(make_pair(tin[u], u));
    if (it != st.end() && tout[it->second] < tout[u]) {
        return -2;
    }
    if (it == st.begin()) {
        return -1;
    }
    --it;
    if (tout[it->second] < tout[u]) {
        return -1;
    }
    int res = it->second;
    st.erase(it);
    return res;
}

void process_time(int u) {
    tin[u] = ++tim;
    for (int v : adj[1][u]) {
        process_time(v);
    }
    tout[u] = ++tim;
}

void dfs(int u) {
    int res = add(u);
    if (res != -2) {
        st.emplace(tin[u], u);
    }
    ans = max(ans, (int) st.size());
    for (int v : adj[0][u]) {
        dfs(v);
    }
    if (res != -2) {
        st.erase(make_pair(tin[u], u));
        if (res != -1) {
            st.emplace(tin[res], res);
        }
    }
}

void solve() {
    cin >> n;
    init();
    for (int it = 0; it < 2; it++) {
        for (int i = 2; i <= n; i++) {
            int x;
            cin >> x;
            adj[it][x].emplace_back(i);
        }
    }
    process_time(1);
    dfs(1);
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}