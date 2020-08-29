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

const int N = 1e7 + 5;

int tc;
int n;
int primes[N];

void solve() {
    inpos(n);
    long long res = 1;
    while (n > 1) {
        int p = primes[n];
        long long mul = 1, strt = p;
        while (n % p == 0) {
            mul += (strt * p - strt);
            n /= p;
            strt *= p * p;
        }
        res *= mul;
    }   
    outpos(res);
}

int main() {
    for (int i = 2; i < N; i++) {
        if (primes[i] != 0) continue;
        for (int j = i; j < N; j += i) {
            primes[j] = i;
        }
    }
    inpos(tc);
    for (int T = 1; T <= tc; T++) {
        solve();
    }
    return 0;
}