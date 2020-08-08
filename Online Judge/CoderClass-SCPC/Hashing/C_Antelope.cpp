#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
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
vector<int> adj[N];
vector<int> comp[N];
int par[N], dist[N], dist2[N];
long long shaker[N];
bitset<N> vis, bad;

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

void dfs(int u) {
    vis[u] = 1;
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        dist[v] = dist[u] + 1;
        dfs(v);
    }
}

pair<int, int> find_center(int k) {
    const int U = k;
    for (int it = 0; it < 2; it++) {
        dist[k] = 0; dfs(k);
        int maks = 0, pos = k;
        for (auto& u : comp[U]) {
            dist2[u] = dist[u], vis[u] = 0;
            if (dist[u] > maks)
                maks = dist[u], pos = u;
        }
        k = pos;
    }
    dist[k] = 0; dfs(k);
    int diameter = 0;
    for (auto& u : comp[U]) {
        if (dist[u] > diameter) diameter = dist[u];
    }
    pair<int, int> ret = {-1, -1};
    for (auto& u : comp[U]) {
        if (dist[u] != diameter / 2 && dist2[u] != diameter / 2) continue;
        if (dist[u] + dist2[u] != diameter) continue;
        if (ret.first == -1)
            ret.first = u;
        else
            ret.second = u;
    }
    return ret;
}

long long rec(int u) {
    vis[u] = 1;
    long long ret = 1;
    vector<long long> Hash;
    for (auto& v : adj[u]) {
        if (vis[v]) continue;
        Hash.emplace_back(rec(v));
    }
    sort(Hash.begin(), Hash.end());
    for (int i = 0; i < (int) Hash.size(); i++) {
        ret = (ret + Hash[i] * shaker[i]);
    }
    return ret;
}

long long get_Hash(int k) {
    pair<int, int> center = find_center(k);
    int root = center.first;
    if (center.second != -1) {
        root = 0; adj[root].clear(); vis[root] = 0;
        int u = center.first, v = center.second;
        adj[root].emplace_back(u); adj[root].emplace_back(v);
        *find(adj[u].begin(), adj[u].end(), v) = root;
        *find(adj[v].begin(), adj[v].end(), u) = root;
    }
    for (auto& u : comp[k]) vis[u] = 0;
    return rec(root);
}

void init() {
    for (int i = 0; i < N; i++) {
        par[i] = i;
        shaker[i] = rand();
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
        int pp = fpar(i);
        if (!bad[i]) {
            comp[pp].emplace_back(i);
            continue;
        }
        bad[pp] = 1;
    }
    long long ans = 0;
    map<long long, int> mp;
    for (int i = 1; i <= n; i++) {
        if (bad[i]) continue;
        if (fpar(i) != i) continue;
        long long Hash = get_Hash(i);
        ans += (1LL) * mp[Hash]++;
    }
    outpos(ans);

    return 0;
}