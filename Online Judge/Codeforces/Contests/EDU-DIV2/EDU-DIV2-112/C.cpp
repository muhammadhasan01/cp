#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 1e5 + 5;
const int K = 2;

int m;
int a[K + 5][N];
long long pre[K + 5][N], suf[K + 5][N];

void solve() {
    cin >> m;
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
        suf[i][m + 1] = 0;
        for (int j = m; j >= 1; j--) {
            suf[i][j] = suf[i][j + 1] + a[i][j];
        }
    }
    long long ans = INF;
    for (int j = 1; j <= m; j++) {
        long long bob = max(pre[2][j - 1], suf[1][j + 1]);
        ans = min(ans, bob);
    }
    cout << ans << '\n';
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