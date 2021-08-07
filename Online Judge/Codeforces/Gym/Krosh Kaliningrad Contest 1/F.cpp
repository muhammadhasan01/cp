#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 3010;
const int MOD = 1e9+7;
 
int n, m;
int cnt[N];
int ans;
vector <int> cur;
int dp[N][N];

void add(int &a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void substract(int &a, int b) {
    a -= b;
    if (a < 0) a += MOD;
}

int get(int m, int n) {
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) dp[1][i] = 1;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (j > 1) add(dp[i][j], dp[i - 1][j - 1]);
            if (j < n) add(dp[i][j], dp[i - 1][j + 1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        add(ans, dp[m][i]);
    }
    return ans;
}

int f(int m, int n) {
    if (n <= 0) return 0;
    return get(m, n);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    int ans = f(m, n);
    int tmp = f(m, n - 1);
    add(tmp, tmp);
    substract(ans, tmp);
    add(ans, f(m, n - 2));
    cout << ans << '\n';

    return 0;
}