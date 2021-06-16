#include <bits/stdc++.h>

using namespace std;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    set<pair<int, int>> edges;
    vector<bool> vis(n + 1);
    auto ask = [&](int u) -> vector<int> {
        vector<int> ret(n + 1);
        cout << "? " << u << endl;
        for (int i = 1; i <= n; i++) {
            cin >> ret[i];
        }
        return ret;
    };
    auto furthest = [&](int u, vector<int>& res) -> pair<int, int> {
        int mx = -1, ret = -1;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            if (res[i] > mx) {
                mx = res[i];
                ret = i;
            }
        }
        return make_pair(mx, ret);
    };
    auto add_edge = [&](int u, int v) -> void {
        edges.emplace(min(u, v), max(u, v));
    };
    auto add = [&](int u, vector<int>& res) -> void {
        for (int i = 1; i <= n; i++) {
            if (res[i] == 1) {
                add_edge(u, i);
            }
        }
    };
    int u = rng32() % n + 1;
    while ((int) edges.size() < n - 1) {
        vector<int> res = ask(u);
        add(u, res);
        if ((int) edges.size() == n - 1) break;
        auto [mx, v] = furthest(u, res);
        if (v == -1) break;
        vector<int> ser = ask(v);
        add(v, ser);
        vector<pair<int, int>> path;
        vector<int> vals(n + 1);
        for (int i = 1; i <= n; i++) {
            if (res[i] + ser[i] == mx) {
                path.emplace_back(res[i], i);
                vis[i] = 1;
                vals[res[i]] = i;
            }
        }
        sort(path.begin(), path.end());
        int len = path.size();
        for (int i = 1; i < len; i++) {
            add_edge(path[i - 1].second, path[i].second);
        }
        for (int i = 1; i <= n; i++) {
            if (res[i] + ser[i] == mx + 2) {
                vis[i] = 1;
                add_edge(vals[res[i] - 1], i);
            }
        }
        auto [_, w] = furthest(u, res); 
        u = w;
    }
    cout << "!" << endl;
    for (auto& [u, v] : edges) {
        cout << u << " " << v << endl;
    }

    return 0;
}