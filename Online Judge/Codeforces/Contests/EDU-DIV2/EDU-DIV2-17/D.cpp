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

const int N = 1e5 + 2;
const long long INF = 1e18;

int n;
int a[4][N];
long long s[N];
long long dp[N][4];

void upd(long long& x, long long y) {
    x = max(x, y);
}

int main() {
    inpos(n);
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            inpos(a[i][j]);
            dp[j][i] = -INF;
            s[j] += a[i][j];
        }
    }
    for (int j = 1; j <= n; j++)
        s[j] += s[j - 1];
    dp[1][1] = a[1][1];
    for (int i = 2; i <= 3; i++) dp[1][i] = dp[1][i - 1] + a[i][1];
    for (int j = 2; j <= n; j++) {
        for (int i = 1; i <= 3; i++) {
            upd(dp[j][i], dp[j - 1][i] + a[i][j]);
            if (i >= 2) upd(dp[j][i], dp[j - 1][i - 1] + a[i - 1][j] + a[i][j]);
            if (i <= 2) upd(dp[j][i], dp[j - 1][i + 1] + a[i + 1][j] + a[i][j]); 
        }
        for (int x = 1; x <= 2; x++) {
            upd(dp[j][1], dp[j - x][3] + s[j] - s[j - x]);
            upd(dp[j][3], dp[j - x][1] + s[j] - s[j - x]);
        }
    }
    outpos(dp[n][3]);
    return 0;
}