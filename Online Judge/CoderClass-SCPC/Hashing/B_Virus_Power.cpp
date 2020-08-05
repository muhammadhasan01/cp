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
const int M = 1e9 + 7;
const int P = 37;

int n;
int pre[N], F[N];

void init() {
    F[0] = 1;
    for (int i = 1; i < N; i++) {
        long long cur = ((long long) P * F[i - 1]) % M;
        F[i] = cur;
    }
}

int get(int l, int r) {
    long long res = pre[r] - pre[l - 1];
    res = (res % M + M) % M;
    res = (res * F[n - r]) % M;
    return (res % M + M) % M;
}

bool check(int len) {
    vector<int> memo(n + 1, -1);
    for (int i = 1; len * len + i - 1 <= n; i++) {
        int res;
        if (memo[i] != -1)
            res = memo[i];
        else
            res = memo[i] = get(i, i + len - 1);
        int cnt = 1;
        for (int j = i + len; j + len - 1 <= n && cnt < len; j += len, ++cnt) {
            int tmp;
            if (memo[j] != -1)
                tmp = memo[j];
            else
                tmp = memo[j] = get(j, j + len - 1);
            if (tmp != res) {
                break;
            }
        }
        if (cnt == len) return true;
    }
    return false;
}

int main() {
    init();
    inpos(n);
    for (int i = 1; i <= n; i++) {
        char x; x = getchar();
        long long cur = ((1LL) * (x - 'a') * F[i - 1]) % M;
        pre[i] = (pre[i - 1] + cur) % M;
    }
    int l = 1, r = n, at = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ((1LL) * mid * mid <= (long long) n) {
            at = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    for (int j = at; j >= 1; j--) {
        if (check(j)) {
            outpos(j);
            return 0;
        }
    }
    return 0;
}