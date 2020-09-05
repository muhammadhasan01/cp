#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, k;
char s[N], t[2];
int dp[N][N][N];

int get(int pos, int x, int rem) {
    if (pos > n) return 0;
    if (dp[pos][x][rem] != -1) return dp[pos][x][rem];
    int ret = get(pos + 1, x, rem);
    int cost = (s[pos] == t[0] ? 0 : 1);
    if (cost <= rem)
        ret = max(ret, get(pos + 1, x + 1, rem - cost));
    cost = (s[pos] == t[1] ? 0 : 1);
    if (cost <= rem)
        ret = max(ret, x + get(pos + 1, x, rem - cost));
    return dp[pos][x][rem] = ret;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 2; i++) {
        cin >> t[i];
    }
    if (t[0] == t[1]) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (s[i] == t[0])
                ++cnt;
        cnt = min(n, cnt + k);
        cout << cnt * (cnt - 1) / 2 << '\n';
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << get(1, 0, k) << '\n';

    return 0;
}