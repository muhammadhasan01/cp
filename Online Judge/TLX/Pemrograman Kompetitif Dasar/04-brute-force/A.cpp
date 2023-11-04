#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    auto getHorizontal = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[n - i - 1][j];
            }
        }
        return ret;
    };

    auto getVertical = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[i][m - j - 1];
            }
        }
        return ret;
    };

    auto getDiagonalRight = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[j][i];
            }
        }
        return ret;
    };

    auto getDiagonalLeft = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[m - j - 1][n - i - 1];
            }
        }
        return ret;
    };

    if (a == b) {
        cout << "identik" << '\n';
    } else if (getHorizontal() == b) {
        cout << "horisontal" << '\n';
    } else if (getVertical() == b) {
        cout << "vertikal" << '\n';
    } else if (getDiagonalLeft() == b) {
        cout << "diagonal kiri bawah" << '\n';
    } else if (getDiagonalRight() == b) {
        cout << "diagonal kanan bawah" << '\n';
    } else {
        cout << "tidak identik" << '\n';
    }
    
    return 0;
}