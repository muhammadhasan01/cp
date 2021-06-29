#include <bits/stdc++.h>

using namespace std;

/** START OF DESPERATE OPTIMIZATION **/
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

template<typename T> void in(T & x) {
    x = 0;
    register T c = getchar();
    while (((c < 48) || (c > 57)) && (c != '-')) c = getchar();
    bool neg = false;
    if (c == '-') neg = true;
    for (; c < 48 || c > 57; c = getchar());
    for (; c > 47 && c < 58; c = getchar()) x = (x << 3) + (x << 1) + (c & 15);
    if (neg) x = -x;
}

template<typename T> void out(T n, char CC) {
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
    putchar(CC);
}
/** END OF DESPERATE OPTIMIZATION **/

const int N = 1e4 + 5;
const int INF = 2e9;

int n;
int a[N];
long long dp[N][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    in(n);
    for (int i = 1; i <= n; i++) {
        in(a[i]);
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = -INF;
        dp[i][1] = INF;
    }
    for (int i = 1; i <= n; i++) {
        long long XOR = 0;
        for (int j = i; j >= 1; j--) {
            XOR = (XOR ^ a[j]);
            dp[i][0] = max(dp[i][0], XOR + dp[j - 1][0]);
            dp[i][1] = min(dp[i][1], XOR + dp[j - 1][1]);
        }
    }
    cout << dp[n][0] - dp[n][1] << '\n';

    return 0;
}