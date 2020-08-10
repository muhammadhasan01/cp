#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int tc;
int n, m;
char a[N][N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i][m] == 'R') ++ans;
    }
    for (int j = 1; j < m; j++) {
        if (a[n][j] == 'D') ++ans;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}