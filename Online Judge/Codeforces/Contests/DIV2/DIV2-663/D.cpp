#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<vector<char>> a;

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

int zero_2(int i) {
    return (a[1][i] != '0') + (a[2][i] != '0');
}

int one_2(int i) {
    return min((a[1][i] != '1') + (a[2][i] != '0'), (a[1][i] != '0') + (a[2][i] != '1'));
}

int two_2(int i) {
    return (a[1][i] != '1') + (a[2][i] != '1');
}

void solve2() {
    int ev = min(zero_2(1), two_2(1));
    int odd = one_2(1);
    for (int i = 2; i <= m; i++) {
        int cur_odd = ev + one_2(i);
        int cur_ev = odd + min(zero_2(i), two_2(i));
        odd = cur_odd, ev = cur_ev;
    }
    cout << min(odd, ev) << '\n';
    exit(0);
}

int zero_3(int i) {
    return (a[1][i] == '0') + (a[2][i] == '0') + (a[3][i] == '0');
}

int one_3(int i) {
    return (a[1][i] == '1') + (a[2][i] == '1') + (a[3][i] == '1');
}

int U1(int i) {
    return (a[1][i] == '1') + (a[2][i] == '1') + (a[3][i] == '0');
}

int U2(int i) {
    return (a[1][i] == '0') + (a[2][i] == '1') + (a[3][i] == '1');
}

int U3(int i) {
    return (a[1][i] == '1') + (a[2][i] == '0') + (a[3][i] == '1');
}

int K1(int i) {
    return (a[1][i] == '1') + (a[2][i] == '0') + (a[3][i] == '0');
}

int K2(int i) {
    return (a[1][i] == '0') + (a[2][i] == '0') + (a[3][i] == '1');
}

int T(int i) {
    return (a[1][i] == '0') + (a[2][i] == '1') + (a[3][i] == '0');
}

void solve3() {
    vector<vector<int>> dp(m + 1, vector<int>(8));
    for (int i = 1; i <= m; i++) {
        // Z
        dp[i][0] = zero_3(i) + min(dp[i - 1][1], dp[i - 1][4]); // OK
        // T
        dp[i][1] = T(i) + min(dp[i - 1][0], dp[i - 1][7]); // OK
        // U1
        dp[i][2] = U1(i) + min(dp[i - 1][5], dp[i - 1][3]); // OK
        // U2
        dp[i][3] = U2(i) + min(dp[i - 1][6], dp[i - 1][2]); // OK
        // U3
        dp[i][4] = U3(i) + min(dp[i - 1][0], dp[i - 1][7]); // OK
        // K1
        dp[i][5] = K1(i) + min(dp[i - 1][2], dp[i - 1][6]); // OK
        // K2
        dp[i][6] = K2(i) + min(dp[i - 1][3], dp[i - 1][5]); // OK
        // O
        dp[i][7] = one_3(i) + min(dp[i - 1][1], dp[i - 1][4]); // OK 
    }
    int ans = INF;
    for (int j = 0; j < 8; j++)
        ans = min(ans, dp[m][j]);
    cout << ans << '\n';
    exit(0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    a.resize(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    if (n > m) {
        vector<vector<char>> b(m + 1, vector<char>(n + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                b[j][i] = a[i][j];
            }
        }
        a.swap(b);
        swap(n, m);
    }
    if (n == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (n == 2) solve2();
    if (n == 3) solve3();
    cout << -1 << '\n';

    return 0;
}