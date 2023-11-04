#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    auto check = [&](int i, int j) -> bool {
        if (i + 8 >= n || j + 8 >= m) {
            return false;
        }
        for (int x = i; x <= i + 2; x++) {
            for (int y = j; y <= j + 2; y++) {
                if (g[x][y] == '.') {
                    return false;
                }
            }
            if (g[x][j + 3] == '#') {
                return false;
            }
        }
        for (int y = j; y <= j + 3; y++) {
            if (g[i + 3][y] == '#') {
                return false;
            }
        }
        for (int x = i + 6; x <= i + 8; x++) {
            for (int y = j + 6; y <= j + 8; y++) {
                if (g[x][y] == '.') {
                    return false;
                }
            }
            if (g[x][j + 5] == '#') {
                return false;
            }
        }
        for (int y = j + 5; y <= j + 8; y++) {
            if (g[i + 5][y] == '#') {
                return false;
            }
        }
        return true;
    };

    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check(i, j)) {
                ans.emplace_back(i + 1, j + 1);
            }
        }
    }
    for (auto& [i, j] : ans) {
        cout << i << ' ' << j << '\n';
    }
    
    return 0;
}