#include <bits/stdc++.h>

using namespace std;

const int K = 2;
const int N = 105;
const long long INF = 1e16;

int n;
char s[N];
int a[N];
long long ans[N][N];
long long dp[K][N][N][N];

long long get_dp(int c, int l, int r, int cnt);
long long get_ans(int l, int r) {
    if (l > r) {
        return 0;
    }
    long long& res = ans[l][r];
    if (res != -1) {
        return res;
    }
    for (int cnt = 1; cnt <= r - l + 1; cnt++) {
        for (int it = 0; it < K; it++) {
            res = max(res, get_dp(it, l, r, cnt) + a[cnt]);
        }
    }
    return res;
}

long long get_dp(int c, int l, int r, int cnt) {
    if (cnt == 0) {
        return get_ans(l, r);
    }
    long long& res = dp[c][l][r][cnt];
    if (res != -1) {
        return res;
    }
    res = -INF;
    for (int i = l; i <= r; i++) {
        int num = s[i] - '0';
        if (num != c) {
            continue;
        }
        res = max(res, get_ans(l, i - 1) + get_dp(c, i + 1, r, cnt - 1));
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    memset(ans, -1, sizeof(ans));
    memset(dp, -1, sizeof(dp));
    cout << get_ans(1, n) << '\n';
    
    return 0;
}