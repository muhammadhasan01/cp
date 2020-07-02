#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const int INF = 2e9;

int n, m;
int a[N][N], b[N][N], t[N][N];
vector<pair<int, int>> ans;

void simulate() {
    for (auto& e : ans) {
        if (e.first == 1) {
            for (int j = 1; j <= m; j++) b[e.second][j]++;
        } else {
            for (int i = 1; i <= n; i++) b[i][e.second]++;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != b[i][j]) {
                cout << -1 << '\n';
                exit(0);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    int mini = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            t[i][j] = a[i][j];
            mini = min(mini, a[i][j]);
        }
    }
    if (mini > 0) {
        if (n <= m) {
            for (int i = 1; i <= n; i++) {
                for (int it = 0; it < mini; it++) ans.emplace_back(1, i);
                for (int j = 1; j <= m; j++) {
                    t[i][j] -= mini;
                }
            }
        } else {
            for (int j = 1; j <= m; j++) {
                for (int it = 0; it < mini; it++) ans.emplace_back(2, j);
                for (int i = 1; i <= n; i++) {
                    t[i][j] -= mini;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cur = INF;
        for (int j = 1; j <= m; j++) {
            cur = min(cur, t[i][j]);
        }
        if (cur == 0) continue;
        for (int it = 0; it < cur; it++) ans.emplace_back(1, i);
        for (int j = 1; j <= m; j++) t[i][j] -= cur;
    }
    for (int j = 1; j <= m; j++) {
        int cur = INF;
        for (int i = 1; i <= n; i++) {
            cur = min(cur, t[i][j]);
        }
        if (cur == 0) continue;
        for (int it = 0; it < cur; it++) ans.emplace_back(2, j);
        for (int i = 1; i <= n; i++) t[i][j] -= cur;
    }
    simulate();
    cout << ans.size() << '\n';
    for (auto& e : ans) {
        cout << (e.first == 1 ? "row" : "col") << " " << e.second << '\n';
    }

    return 0;
}