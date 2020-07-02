#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int tc;
int n, k;
char a[N][N];

void answer() {
    int maxRow = 0, minRow = n, maxCol = 0, minCol = n;
    for (int i = 1; i <= n; i++) {
        int row = 0, col = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j][i] == '1') ++row;
            if (a[i][j] == '1') ++col;
        }
        maxRow = max(maxRow, row);
        minRow = min(minRow, row);
        maxCol = max(maxCol, col);
        minCol = min(minCol, col);
    }
    int res = (maxRow - minRow) * (maxRow - minRow);
    res += (maxCol - minCol) * (maxCol - minCol);
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = '0';
        }
    }
    if (k == 0) {
        answer();
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[i][i] = '1';
        if (--k == 0) break;
    }
    for (int j = 2; j <= n; j++) {
        if (k == 0) break;
        for (int i = 1, p = j; i <= n - j + 1; i++, p++) {
            a[i][p] = '1';
            if (--k == 0) break;
        }
        if (k == 0) break;
        for (int i = n, p = j - 1; i >= n - j + 2; i--, p--) {
            a[i][p] = '1';
            if (--k == 0) break;
        }
    }
    answer();
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}