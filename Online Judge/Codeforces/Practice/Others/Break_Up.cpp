#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;
int n, m, s, t;
long long w[N];
int tin[N], ret[N], timer;
vector<pair<int, int>> g[N];
bool used[N], bridge[N];
vector<int> e, vect, br;
long long ans, ans1, ans2;

void dfs(int u) {
    used[u] = 1;
    for (auto el : g[u]) {
        int v = el.first;
        int id = el.second;
        if (!used[v]) {
            e.push_back(id);
            dfs(v);
        }
    }
}

void rec(int v, int id, int par = -1) {
    if (v == t)
        br = vect;

    used[v] = 1;
    ret[v] = tin[v] = ++timer;

    for (auto e : g[v]) {
        int to = e.first;
        int idx = e.second;
        if (idx == id || idx == par) continue;

        if (!used[to]) {
            vect.push_back(idx);
            rec(to, id, idx);
            vect.pop_back();
            ret[v] = min(ret[v], ret[to]);

            if (tin[v] < ret[to]) {
                bridge[idx] = 1;
            }
        } else {
            ret[v] = min(ret[v], tin[to]);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v >> w[i];
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }

    dfs(s);

    if (!used[t]) {
        cout << "0\n0\n";
        return 0;
    }

    ans = inf;
    for (int i = 0; i < (int) e.size(); i++) {
        memset(used, 0, sizeof(used));
        memset(bridge, 0, sizeof(bridge));
        vect.clear(); br.clear();
        timer = 0;

        long long W = inf;
        int ind = -1;

        rec(s, e[i]);

        if ((int) br.size() == 0) {
            W = 0, ind = -1;
        }

        for (auto e : br) {
            if (bridge[e] && w[e] < W) {
                W = w[e];
                ind = e;
            }
        }

        if (W != inf && ans > W + w[e[i]]) {
            ans = W + w[e[i]];
            ans1 = e[i];
            ans2 = ind;
        }
    }

    if (ans == inf) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
        if (ans2 == -1) {
            cout << 1 << '\n' << ans1 << '\n';
        } else {
            cout << 2 << '\n' << ans1 << ' ' << ans2 << '\n';
        }
    }

    return 0;
}
