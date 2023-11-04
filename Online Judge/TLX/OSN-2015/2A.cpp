#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int m, n, k;
    cin >> m >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y] = a[i];
        cin >> x >> y;
    }

    int minSame = INT_MAX;
    vector<int> ans(2 * m, INF);
    queue<int> q;

    auto check = [&](int i, int j) -> void {
        auto [xi, yi] = a[i];
        auto [xj, yj] = a[j];
        if (yi == yj) {
            if (xi > xj) {
                swap(xi, xj);
            }
            minSame = min({minSame, xj - xi, xi + m - xj});
            return;
        }
        if (yi == -1) {
            swap(xi, xj);
        }
        int tim = (xi <= xj ? xj - xi : xj + m - xi);
        for (int t : {tim, tim + m}) {
            int cur = t % (2 * m);
            if (ans[cur] == INF) {
                q.emplace(cur);
                ans[cur] = 0;  
            }
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            check(i, j);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : {u - 1, u + 1}) {
            v = (v + 2 * m) % (2 * m);
            if (ans[v] == INF) {
                ans[v] = ans[u] + 1;
                q.emplace(v);
            }
        }
    }
    while (k--) {
        int tim;
        cin >> tim;
        cout << min(ans[(2 * tim) % (2 * m)], minSame) << '\n';
    }
    
    return 0;
}