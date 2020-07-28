#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define inchar          getchar
#define outchar(x)      putchar(x)

template<typename T> void inpos(T & x) {
    x = 0;
    register T c = inchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = inchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = inchar());
    for (; c > 47 && c < 58; c = inchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void outpos(T n) {
    if (n < 0) {
        outchar('-');
        n *= -1;
    }
    char snum[65];
    int i = 0;
    do {
        snum[i++] = n % 10 + '0';
        n /= 10;
    } while (n);
    i = i - 1;
    while (i >= 0) outchar(snum[i--]);
    outchar('\n');
}

const int N = 2e2 + 5;
const int M = 30 * N;

int n, k;
int two[N], five[N];
int dp[2][N][M];
bool can[2][N][M];

int main() {
    inpos(n), inpos(k);
    for (int i = 1; i <= n; i++) {
        long long x;
        inpos(x);
        while (x % 2 == 0) {
            x /= 2;
            two[i]++;
        }
        while (x % 5 == 0) {
            x /= 5;
            five[i]++;
        }
    }
    can[0][0][0] = 1;
    for (int it = 1; it <= n; it++) {
        int now = (it & 1);
        int bfr = !(it & 1);
        for (int j = 0; j <= k; j++)
            for (int x = 0; x < M; x++)
                dp[now][j][x] = can[now][j][x] = 0;
        for (int j = 0; j <= k; j++) {
            for (int x = 0; x < M; x++) {
                if (!can[bfr][j][x]) continue;
                dp[now][j][x] = max(dp[now][j][x], dp[bfr][j][x]);
                can[now][j][x] = 1;
                if (j == k) continue;
                if (five[it] + x >= M) continue;
                can[now][j + 1][five[it] + x] = 1;
                int& cur = dp[now][j + 1][five[it] + x];
                cur = max(cur, two[it] + dp[bfr][j][x]);
            }
        }
    }
    int ans = 0, now = (n & 1);
    for (int x = 0; x < M; x++) {
        ans = max(ans, min(dp[now][k][x], x));
    }
    outpos(ans);
    return 0;
}