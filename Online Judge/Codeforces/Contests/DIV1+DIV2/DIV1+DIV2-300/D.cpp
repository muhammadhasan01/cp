#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    vector<pair<int, int>> os, xs, dots;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'o') {
                os.emplace_back(i, j);
                xs.emplace_back(i, j);
            } else if (a[i][j] == 'x') {
                xs.emplace_back(i, j);
            } else if (a[i][j] == '.') {
                dots.emplace_back(i, j);
            }
        }
    }
    set<pair<int, int>> dirs;
    for (auto& [i, j] : xs) {
        for (auto& [ci, cj] : os) {
            int di = i - ci;
            int dj = j - cj;
            dirs.emplace(di, dj);
        }
    }
    for (auto& [i, j] : dots) {
        for (auto& [ci, cj] : os) {
            int di = i - ci;
            int dj = j - cj;
            pair<int, int> cur = make_pair(di, dj);
            dirs.erase(cur);
        }
    }
    for (auto& [i, j] : xs) {
        bool ok = false;
        for (auto& [ci, cj] : os) {
            int di = i - ci;
            int dj = j - cj;
            pair<int, int> cur = make_pair(di, dj);
            if (dirs.find(cur) != dirs.end()) {
                ok = true;
                break;
            }
        }
        if (ok) {
            continue;
        }
        cout << "NO" << '\n';
        return 0;
    }
    int m = 2 * n - 1;
    vector<vector<char>> ans(m + 1, vector<char>(m + 1, '.'));
    int px = (m + 1) / 2;
    int py = px;
    for (auto& [di, dj] : dirs) {
        int ci = px + di;
        int cj = py + dj;
        if (ci < 1 || ci > m || cj < 1 || cj > m) {
            continue;
        }
        ans[ci][cj] = 'x';
    }
    ans[px][py] = 'o';
    cout << "YES" << '\n';
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}