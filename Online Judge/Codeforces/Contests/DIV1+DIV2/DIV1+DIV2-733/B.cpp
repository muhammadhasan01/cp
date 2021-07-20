#include <bits/stdc++.h>

using namespace std;

const int N = 25;
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int n, m;
char ans[N][N];

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans[i][j] = '0';
        }
    }
}

bool check(int i, int j) {
    for (int it = 0; it < 8; it++) {
        int ni = i + dx[it];
        int nj = j + dy[it];
        if (ni < 1 || ni > n || nj < 1 || nj > m) {
            continue;
        }
        if (ans[ni][nj] == '1') {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    init();
    for (int j = 1; j <= m; j++) {
        if (check(1, j)) {
            ans[1][j] = '1';
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check(i, m)) {
            ans[i][m] = '1';
        }
    }
    for (int j = m; j >= 1; j--) {
        if (check(n, j)) {
            ans[n][j] = '1';
        }
    }
    for (int i = n; i >= 1; i--) {
        if (check(i, 1)) {
            ans[i][1] = '1';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}