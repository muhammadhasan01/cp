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
    vector<int> pos(m);
    for (int j = 0; j < m; j++) {
        pos[j] = a[0][j] % 7;
        if (pos[j] == 0) {
            pos[j] = 7;
        }
    }
    for (int j = 1; j < m; j++) {
        if (pos[j] - pos[j - 1] != 1) {
            cout << "No" << '\n';
            return 0;
        }
        if (a[0][j] - a[0][j - 1] != 1) {
            cout << "No" << '\n';
            return 0;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] - a[i - 1][j] != 7) {
                cout << "No" << '\n';
                return 0;
            }
        }
    }
    cout << "Yes" << '\n';
    
    return 0;
}