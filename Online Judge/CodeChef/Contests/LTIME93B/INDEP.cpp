#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int pr[2] = {29, 31};

int n, m;
vector<int> adj[N];
long long pre[N][2];

void init() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
    }
}

void solve() {
    cin >> n >> m;
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    vector<tuple<int, int, int>> v;
    for (int u = 1; u <= n; u++) {
        sort(adj[u].begin(), adj[u].end());
        vector<long long> val(2);
        int c = 0;
        for (int e : adj[u]) {
            for (int it = 0; it < 2; it++) {
                val[it] = (val[it] + (1LL) * e * pre[c][it]) % M;
            }
            ++c;
        }
        v.emplace_back(val[0], val[1], u);
    }
    sort(v.begin(), v.end());
    tuple<int, int, int> cur = v[0];
    int ans = 0, cnt = 0, pos = 0;
    for (int i = 0; i < n; i++) {
        if (get<0>(cur) == get<0>(v[i]) && get<1>(cur) == get<1>(v[i])) {
            ++cnt;
        } else {
            if (cnt + (int) adj[get<2>(cur)].size() == n) {
                ++ans;
                pos = get<2>(cur);
            }
            cnt = 1;
            cur = v[i];
        }
    }
    if (cnt + (int) adj[get<2>(cur)].size() == n) {
        ++ans;
        pos = get<2>(cur);
    }
    cout << ans << '\n';
    vector<bool> ok(n + 1, true);
    if (ans == 0) {
        fill(ok.begin(), ok.end(), false);
    } else {
        for (int e : adj[pos]) ok[e] = false;
    }
    for (int i = 1; i <= n; i++)
        cout << ok[i];
    cout << '\n';
}    

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    pre[0][0] = pre[0][1] = 1;
    for (int i = 1; i < N; i++) {
        for (int it = 0; it < 2; it++) {
            pre[i][it] = (1LL) * pr[it] * pre[i - 1][it];
            pre[i][it] %= M;
        }
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}