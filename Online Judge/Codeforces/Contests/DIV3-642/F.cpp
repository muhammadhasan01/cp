#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;
const long long INF = 1e18;

int tc;
int n, m;
long long a[N][N];
long long dp[N][N];

long long get(long long x) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][1] = dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long y = x + (i + j - 2);
            if (y > a[i][j]) continue;
            dp[i][j] = min(INF, a[i][j] - y + min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    return dp[n][m];
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        set<long long> st;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                st.insert(a[i][j] - (i + j - 2));
            }
        }
        long long ans = INF;
        for (auto& e : st) {
            ans = min(ans, get(e));
        }
        cout << ans << '\n';
    }

    return 0;
}