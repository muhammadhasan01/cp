#include <bits/stdc++.h>

using namespace std;

const string BW = "BW";

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int parity = 0;
        for (int j = 0; j < m; j++) {
            if (g[i][j] != '.') {
                parity ^= 1;
            }
        }
        if (parity) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int j = 0; j < m; j++) {
        int parity = 0;
        for (int i = 0; i < n; i++) {
            if (g[i][j] != '.') {
                parity ^= 1;
            }
        }
        if (parity) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<vector<int>> H(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'L') {
                H[j].emplace_back(i);
            }
        }
    }
    vector<vector<int>> V(n);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (g[i][j] == 'U') {
                V[i].emplace_back(j);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        int len = (int) H[j].size();
        if (len & 1) {
            cout << -1 << '\n';
            return;
        }
        int x = 0;
        for (int i : H[j]) {
            g[i][j] = BW[x];
            g[i][j + 1] = BW[1 - x];
            x ^= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        int len = (int) V[i].size();
        if (len & 1) {
            cout << -1 << '\n';
            return;
        }
        int x = 0;
        for (int j : V[i]) {
            g[i][j] = BW[x];
            g[i + 1][j] = BW[1 - x];
            x ^= 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                continue;
            }
            if (g[i][j] != BW[0] && g[i][j] != BW[1]) {
                cout << -1 << '\n';
                return;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
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