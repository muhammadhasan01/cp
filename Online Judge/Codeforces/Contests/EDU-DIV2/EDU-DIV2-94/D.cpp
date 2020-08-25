#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        putchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) putchar(snum[i--]);
    putchar('\n');
}

const int N = 3e3 + 5;

int tc;
int n, a[N];
int last[N][N];
int dp[N][N], pre[N][N];

void init() {
    for (int i = 1; i <= n + 3; i++) {
        for (int j = 1; j <= n + 3; j++) {
            dp[i][j] = pre[i][j] = 0;
            last[i][j] = n + 1;
        }
    }
}

void solve() {
    inpos(n);
    init();
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i + 1][j];
            pre[i][j] = pre[i + 1][j];
            last[i][j] = last[i + 1][j];
        }
        dp[i][a[i]]++, pre[i][a[i]]++;
        last[i][a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
        int pos = last[i + 1][a[i]];
        for (int j = 1; j <= n; j++) {
            dp[i][j] += dp[pos][j];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n - 3; i++) {
        for (int j = i + 1; j <= n - 2; j++) {
            int k = last[j + 1][a[i]];
            if (k >= n) continue;
            int cur = dp[k][a[j]];
            if (a[i] == a[j]) {
                cur = pre[k][a[j]];
                cur = (cur * (cur - 1)) / 2;
            }
            ans += cur;
        }
    }
    cout << ans << '\n';
}

int main() {
    inpos(tc);
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    return 0;
}