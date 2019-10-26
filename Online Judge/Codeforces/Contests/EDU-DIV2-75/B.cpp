#include <bits/stdc++.h>

using namespace std;

const int N = 55;
int q;
int n;
int len[N];
int x = 0, y = 0;
int dp[2501][2501][2];

int get(int a, int b, int i) {
    if (i > n) return 0;
    int it = i & 1;
    if (dp[a][b][it] != -1) return dp[a][b][it];
    if (len[i] & 1) {
        for (int j = 0; j <= len[i]; j++) {
            if (a >= j && len[i] - j <= b) dp[a][b][it] = max(dp[a][b][it], 1 + get(a - j, b - (len[i] - j), i + 1));
            if (b >= j && len[i] - j <= a) dp[a][b][it] = max(dp[a][b][it], 1 + get(a - (len[i] - j), b - j, i + 1));
        }
    } else {
        int k = len[i] / 2;
        for (int j = 0; j <= len[i]; j += 2) {
            if (a >= j && len[i] - j <= b) dp[a][b][it] = max(dp[a][b][it], 1 + get(a - j, b - (len[i] - j), i + 1));
            if (b >= j && len[i] - j <= a) dp[a][b][it] = max(dp[a][b][it], 1 + get(a - (len[i] - j), b - j, i + 1));
        }
    }
    dp[a][b][it] = max(0, dp[a][b][it]);
    return dp[a][b][it];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        memset(dp, -1, sizeof(dp));
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            len[i] = (int) s.size();
            for (auto e : s) if (e == '0') x++; else y++;
        }

        sort(len + 1, len + 1 + n);

        cout << get(x, y, 1) << '\n';
    }

    return 0;
}
