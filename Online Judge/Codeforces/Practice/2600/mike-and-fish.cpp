#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int M = 2 * N;
const char RED = 'r';
const char BLUE = 'b';

int n;
char color[N];
bool vis[M];
int deg[M], balance[M];
set<pair<int, int>> adj[M];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        v += N;
        adj[u].emplace(v, i);
        adj[v].emplace(u, i);
        deg[u]++;
        deg[v]++;
    }
    auto remove_edge = [&](int u, int v, int id) {
        adj[u].erase(make_pair(v, id));
        adj[v].erase(make_pair(u, id));
        deg[u]--;
        deg[v]--;
    };
    deque<tuple<int, int, int>> odd;
    {
        queue<int> q;
        for (int u = 0; u < M; u++) {
            if (deg[u] > 0) {
                q.emplace(u);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (deg[u] % 2 == 0) {
                continue;
            }
            auto [v, id] = *adj[u].begin();
            remove_edge(u, v, id);
            odd.emplace_front(u, v, id);
            q.emplace(v);
        }
    }
    vector<pair<int, int>> circuits;
    auto euler_circuit = [&](int s) {
        vector<pair<int, int>> st;
        st.emplace_back(s, -1);
        while (!st.empty()) {
            auto [u, i] = st.back();
            vis[u] = true;
            if (adj[u].empty()) {
                circuits.emplace_back(u, i);
                st.pop_back();
            } else {
                auto [v, id] = *adj[u].begin();
                st.emplace_back(v, id);
                remove_edge(u, v, id);
            }
        }
    };
    for (int u = 0; u < M; u++) {
        if (deg[u] > 0 && !vis[u]) {
            euler_circuit(u);
        }
    }
    int len = circuits.size();
    for (int i = len - 1, j = 0, u = -1; i >= 0; i--, j++) {
        auto [v, id] = circuits[i];
        if (id == -1) {
            u = v;
            continue;
        }
        if (j % 2 == 0) {
            balance[u]--;
            balance[v]--;
            color[id] = BLUE;
        } else {
            balance[u]++;
            balance[v]++;
            color[id] = RED;
        }
        u = v;
    }
    for (auto& [u, v, id] : odd) {
        if (balance[v] > 0) {
            balance[u]--;
            balance[v]--;
            color[id] = BLUE;
        } else {
            balance[u]++;
            balance[v]++;
            color[id] = RED;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i];
    }
    cout << '\n';

    return 0;
}