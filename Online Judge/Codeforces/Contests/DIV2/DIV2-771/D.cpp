#include <bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    auto check = [&](int num, int x1, int y1, int x2, int y2) -> bool {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                if (a[i][j] == 0 || a[i][j] == num) {
                    continue;
                }
                return false;
            }
        }
        return true;
    };

    auto getPoints = [&](int i, int j) -> vector<pair<int, int>> {
        vector<pair<int, int>> points;
        for (int dx : {-1, 1}) {
            for (int dy : {-1, 1}) {
                int ci = i + dx;
                int cj = j + dy;
                if (ci < 1 || cj < 1 || ci > n || cj > m) {
                    continue;
                }
                points.emplace_back(ci, cj);
            }
        }
        return points;
    };

    auto getIdx = [&](int x1, int y1, int x2, int y2) -> vector<pair<int, int>> {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        vector<pair<int, int>> idx;
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                idx.emplace_back(i, j);
            }
        }
        return idx;
    };

    auto fill = [&](int x1, int y1, int x2, int y2) -> void {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        for (int i = x1; i <= x2; i++) {
            for (int j = y1; j <= y2; j++) {
                a[i][j] = 0;
            }
        }
    };

    auto surround = [&](int x1, int y1, int x2, int y2) -> vector<pair<int, int>> {
        if (x1 > x2) {
            swap(x1, x2);
        }
        if (y1 > y2) {
            swap(y1, y2);
        }
        vector<pair<int, int>> idx;
        for (int i = x1 - 1; i <= x2 + 1; i++) {
            for (int j = y1 - 1; j <= y2 + 1; j++) {
                if (i < 1 || i > n || j < 1 || j > m) {
                    continue;
                }
                if (x1 <= i && i <= x2 && y1 <= j && j <= y2) {
                    continue;
                }
                if (a[i][j] == 0) {
                    continue;
                }
                idx.emplace_back(i, j);
            }
        }
        return idx;
    };

    vector<vector<bool>> vis(n + 1, vector<bool>(m + 1));
    queue<pair<int, int>> q;
    bool start = true;
    for (int i = 1; i <= n && start; i++) {
        for (int j = 1; j <= m && start; j++) {
            vector<pair<int, int>> points = getPoints(i, j);
            for (auto& [ci, cj] : points) {
                if (check(a[i][j], i, j, ci, cj)) {
                    for (auto [x, y] : getIdx(i, j, ci, cj)) {
                        q.emplace(x, y);
                    }
                    start = false;
                    break;
                }
            }
        }
    }
    vector<tuple<int, int, int>> ans;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        if (a[i][j] == 0) {
            continue;
        }
        vector<pair<int, int>> points = getPoints(i, j);
        for (auto& [ci, cj] : points) {
            if (check(a[i][j], i, j, ci, cj)) {
                ans.emplace_back(a[i][j], min(i, ci), min(j, cj));
                fill(i, j, ci, cj);
                for (auto [x, y] : surround(i, j, ci, cj)) {
                    q.emplace(x, y);
                }
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << (int) ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto& [c, i, j] : ans) {
        cout << i << ' ' << j << ' ' << c << '\n';
    }
    
    return 0;
}