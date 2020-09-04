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

const int N = 3e5 + 5;

int n, m;
int a[N], pos[N];
vector<int> adj[N];

int main() {
    inpos(n), inpos(m);
    for (int i = 1; i <= n; i++) {
        inpos(a[i]);
        pos[a[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        inpos(u), inpos(v);
        adj[pos[u]].emplace_back(pos[v]);
        adj[pos[v]].emplace_back(pos[u]);
    }
    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    long long ans = (1LL) * n * (n + 1) / 2LL;
    int maxi = 0;
    for (int i = 2; i <= n; i++) {
        auto it = upper_bound(adj[i].begin(), adj[i].end(), i);
        if (it != adj[i].begin()) {
            --it;
            maxi = max(maxi, *it);
        }
        ans -= (1LL) * maxi;
    }
    outpos(ans);
    return 0;
}