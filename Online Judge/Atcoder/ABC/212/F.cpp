#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> depart(n + 1);
    vector<vector<int>> arrive(n + 1);
    map<pair<int, int>, int> mp;
    vector<pair<int, int>> edges(m);
    int numId = 0;
    for (int i = 0; i < m; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        depart[a].emplace_back(s);
        arrive[b].emplace_back(t);
        if (!mp.count({a, s})) {
            mp[{a, s}] = ++numId;
        }
        if (!mp.count({b, t})) {
            mp[{b, t}] = ++numId;
        }
        edges[i] = make_pair(mp[{a, s}], mp[{b, t}]);
    }
    int lg = ceil(log2(numId)) + 3;
    vector<vector<int>> up(numId + 1, vector<int>(lg));
    for (int x = 1; x <= n; x++) {
        sort(depart[x].begin(), depart[x].end());
        sort(arrive[x].begin(), arrive[x].end());
        for (int y : arrive[x]) {
            auto it = upper_bound(depart[x].begin(), depart[x].end(), y);
            if (it != depart[x].end()) {
                int L = mp[{x, y}];
                int R = mp[{x, *it}];
                up[L][0] = R;
            }
        }
    }
    for (auto& [u, v] : edges) {
        up[u][0] = v;
    }
    vector<pair<int, int>> vals(numId + 1);
    for (auto& [p, id] : mp) {
        vals[id] = p;
        if (up[id][0] == 0) {
            up[id][0] = id;
        }
    }
    for (int l = 1; l < lg; l++) {
        for (int u = 1; u <= numId; u++) {
            up[u][l] = up[up[u][l - 1]][l - 1];
        }
    }

    auto answerQuery = [&](int x, int y, int z) -> void {
        auto it = lower_bound(depart[y].begin(), depart[y].end(), x);
        if (it == depart[y].end()) {
            cout << y << '\n';
            return;
        }
        if (*it >= z) {
            cout << y << '\n';
            return;
        }
        int u = mp[{y, *it}];
        for (int l = lg - 1; l >= 0; l--) {
            auto [city, t] = vals[up[u][l]];
            if (t < z) {
                u = up[u][l];
            }
        }
        auto [S, _] = vals[u];
        auto [E, __] = vals[up[u][0]];
        if (S == E) {
            cout << S << '\n';
            return;
        }
        cout << S << ' ' << E << '\n';
    };

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        answerQuery(x, y, z);
    }
    
    return 0;
}