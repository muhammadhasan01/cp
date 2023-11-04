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

    for (int it = 1; it <= n; it++) {
        int lastFilledIndex = -1;
        for (int i = 0; i < n; i++) {
            bool isFilled = true;
            for (int j = 0; j < m; j++) {
                if (g[i][j] == '0') {
                    isFilled = false;
                    break;
                }
            }
            if (isFilled) {
                for (int j = 0; j < m; j++) {
                    g[i][j] = '0';
                }
                lastFilledIndex = i;
            }
        }
        if (lastFilledIndex == -1) {
            break;
        }
        for (int j = 0; j < m; j++) {
            for (int i = lastFilledIndex; i >= 0; i--) {
                if (g[i][j] == '1') {
                    int k = i;
                    while (k + 1 < n && g[k + 1][j] == '0') {
                        swap(g[k][j], g[k + 1][j]);
                        k++;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}