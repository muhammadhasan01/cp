#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector a(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }

    auto getMatrix = [&]() -> vector<vector<int>> {
        vector<vector<int>> suf(n + 2, vector<int>(n + 2));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                suf[i][j] = (a[i][j] ^ suf[i - 1][j + 1]);
            }
        }
        vector<vector<int>> res(n + 1, vector<int>(n + 1));
        for (int i = n; i > 1; i--) {
            for (int j = 1; j < i; j++) {
                res[i][j] = (suf[i][j + 1] ^ suf[j][i + 1]);
                if (i + 1 <= n) {
                    res[i][j] ^= res[i + 1][j + 1];
                }
            }
        }
        return res;
    };

    auto res = getMatrix();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            swap(a[i][j], a[i][n - j + 1]);
        }
    }
    auto res2 = getMatrix();
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            ans ^= res[i][j];
        }
    }
    for (int i = 1, j = n; i <= n / 2; i++, j--) {
        ans ^= res2[j][i];
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}