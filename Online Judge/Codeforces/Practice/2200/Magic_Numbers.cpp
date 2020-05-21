#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;
const int N = 2e3 + 5;

int m, d;
string s1, s2;
int dp[N][N][2];

int get(const string& s) {
    int n = s.length();
    memset(dp, 0, sizeof(dp));
    dp[0][0][1] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 2; k++) {
                for (int p = 0; p <= (k ? int(s[i] - '0') : 9); p++) {
                    if ((i & 1) && (p != d)) continue;
                    if (!(i & 1) && (p == d)) continue;
                    if (i == 0 && p == 0) continue;
                    int ni = i + 1;
                    int nj = (10 * j + p) % m;
                    int nk = (k && (p == int(s[i] - '0')));
                    dp[ni][nj][nk] = (dp[ni][nj][nk] + dp[i][j][k]) % M;
                }
            }
        }
    }
    int ret = 0;
    for (int k = 0; k < 2; k++) {
        ret = (ret + dp[n][0][k]) % M;
    }
    return ret;
}

bool check(const string& s) {
    int n = s.length();
    int res = 0;
    for (int i = 0; i < n; i++) {
        int curd = (s[i] - '0');
        if ((i & 1) && (curd != d)) return false;
        if (!(i & 1) && (curd == d)) return false;
        res = (res * 10 + curd) % m;
    }
    return (res == 0);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> d >> s1 >> s2;
    int ans = get(s2) - get(s1) + check(s1);
    cout << (ans % M + M) % M << "\n";

    return 0;
}