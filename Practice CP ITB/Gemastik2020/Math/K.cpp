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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    inpos(n);
    vector<long long> v(n);
    for (int i = 0; i < n; i++) {
        inpos(v[i]);
    }
    sort(v.rbegin(),v.rend());
    long long sig = 1;
    while(sig <= v[0])
        sig <<= 1;
    sig >>= 1;
    for (int it = 0; sig >= 1; sig >>= 1) {
        int i = it;
        while (i < n && (v[i] & sig) == 0)
            i++;
        if (i >= n)
            continue;
        swap(v[it], v[i]);
        for (int j = 0; j < n; j++) {
            if (j == it) continue;
            if ((v[j] & sig) == 0) continue;
            v[j] = (v[j] ^ v[it]);
        }
        it++;
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans ^= v[i];
    }
    outpos(ans);
    
    return 0;
}