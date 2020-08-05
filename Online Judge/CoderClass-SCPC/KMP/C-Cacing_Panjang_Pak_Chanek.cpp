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

const int N = 1e5 + 5;
const int M = 1e9 + 9;
const int P = 31;

int n;
char s[N];
int pre[N], suf[N], F[N];

void init() {
    F[0] = 1;
    for (int i = 1; i < N; i++) {
        long long cur = ((long long) P * F[i - 1]) % M;
        F[i] = cur;
    }
}

int main() {
    init();
    inpos(n);
    for (int i = 1; i <= n; i++) {
        s[i - 1] = getchar();
        long long cur = ((1LL) * (s[i - 1] - 'A' + 1) * F[i - 1]) % M;
        pre[i] = (pre[i - 1] + cur) % M;
    }
    for (int i = n; i >= 1; i--) {
        long long cur = ((1LL) * (s[i - 1] - 'A' + 1) * F[n - i]) % M;
        suf[i] = (suf[i + 1] + cur) % M;
    }
    int ans = 0;
    vector<bool> ok(n + 1);
    for (int i = 0; i <= n / 2; i++) {
        if (pre[i] == suf[n - i + 1])
            ok[i] = 1;
    }
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
        int L = (i + 1) - d1[i];
        if (ok[L] && 2 * L + 2 * d1[i] - 1 <= n)
            ans = max(ans, 2 * L + 2 * d1[i] - 1);
        int R = (i + 1) + d1[i];
        if (ok[n - R + 1] && 2 * (n - R + 1) + 2 * d1[i] - 1 <= n)
            ans = max(ans, 2 * (n - R + 1) + 2 * d1[i] - 1);
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
        int L = (i + 1) - d2[i] - 1;
        if (ok[L] && 2 * L + 2 * d2[i] <= n)
            ans = max(ans, 2 * L + 2 * d2[i]);
        int R = (i + 1) + d2[i];
        if (ok[n - R + 1] && 2 * (n - R + 1) + 2 * d2[i] <= n)
            ans = max(ans, 2 * (n - R + 1) + 2 * d2[i]);
    }
    outpos(ans);
    return 0;
}