#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
const long long M = 1e9 + 7;
const long long P[2] = {31, 37};

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

int n, m;
int nodes;
vector<int> adj[N];
int par[N], sz[N];
bitset<N> checked;
bitset<N> bad;
long long HASH[2], K[2];

void dfs(int u, int p) {
    nodes++; sz[u] = 1;
    for (auto v : adj[u]) {
        if (v == p || checked[v] == 1) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int centroid(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p || checked[v] == 1) continue;
        if (sz[v] > nodes) return centroid(v, u);
    }
    return u;
}

void decompose(int u, int p, int h) {
    nodes = 0; dfs(u, u); nodes /= 2;
    int v = centroid(u, u);
    checked[v] = 1;
    for (int it = 0; it < 2; it++) {    
        K[it] = (K[it] * P[it]) % M; HASH[it] = (HASH[it] + K[it]);
        K[it] = (K[it] * P[it]) % M; HASH[it] = (HASH[it] + (K[it] * (long long) h)) % M;
    }
    // cerr << "("; cerr << char(int('a') + h);
    for (auto w : adj[v]) {
        if (checked[w] == 1) continue;
        decompose(w, v, h + 1);
    }
    // cerr << ")";
    for (int it = 0; it < 2; it++) {
        K[it] = (K[it] * P[it]) % M; HASH[it] = (HASH[it] + K[it]);
    }
}

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

bool merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return false;
    par[pu] = pv;
    return true;
}

void init() {
    for (int i = 1; i <= n; i++) {
        par[i] = i;
    }
}

int main() {
    inpos(n), inpos(m);
    init();
    for (int i = 1; i <= m; i++) {
        int u, v;
        inpos(u), inpos(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
        if (!merge(u, v)) {
            bad[u] = bad[v] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) continue;
        int pp = fpar(i);
        bad[pp] = 1;
    }
    long long res = 0;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        if (bad[i]) continue;
        if (fpar(i) != i) continue;
        for (int it = 0; it < 2; it++) {
            HASH[it] = 0, K[it] = 1;
        }
        decompose(i, i, 2);
        // cerr << '\n';
        // cerr << i << " => " << HASH[it] << "\n";
        pair<int, int> cur = make_pair(HASH[0], HASH[1]);
        res += (1LL) * mp[cur]++;
    }
    outpos(res);

    return 0;
}