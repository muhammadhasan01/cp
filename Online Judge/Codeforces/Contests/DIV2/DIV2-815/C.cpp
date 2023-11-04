#include <bits/stdc++.h>

using namespace std;

const int DX[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int DY[] = {1, -1, 0, 0, 1, 1, -1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    int one = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '1') {
                one++;
            }
        }
    }
    int type = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                continue;
            }
            type = 0;
            for (int k = 0; k < 8; k++) {
                int ci = i + DX[k];
                int cj = j + DY[k];
                if (ci < 0 || cj < 0 || ci >= n || cj >= m) {
                    continue;
                }
                if (g[ci][cj] == '0') {
                    cout << one << '\n';
                    return;
                }
            }
        }
    }
    if (type == -1) {
        cout << one - 2 << '\n';
        return;
    }
    cout << one - 1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}