#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
        a[i][m] = INF;
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; i++) {
        int pos = -1;
        for (int j = 0; j + 1 < m; j++) {
            if (a[i][j] > a[i][j + 1]) {
                pos = j;
                break;
            }
        }
        if (pos == -1) {
            continue;
        }
        for (int j = pos + 1; j < m; j++) {
            if (a[i][j + 1] >= a[i][pos] && a[i][j] <= a[i][pos + 1]) {
                l = pos, r = j;
                break;
            }
        }
        if (l == -1) {
            cout << -1 << '\n';
            return;
        }
        while (l > 0 && a[i][l - 1] == a[i][pos]) {
            l--;
        }
        break;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i][l], a[i][r]);
        if (is_sorted(a[i].begin(), a[i].end())) {
            continue;
        }
        cout << -1 << '\n';
        return;
    }
    cout << l + 1 << ' ' << r + 1 << '\n';
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