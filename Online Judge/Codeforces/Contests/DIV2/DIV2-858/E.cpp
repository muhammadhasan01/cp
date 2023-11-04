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

const int N = 2e5 + 10;
const int L = ceil(log2(N)) + 2;

int up[N][L];
int depth[N], tin[N], tout[N], tim;
int a[N];
long long dp[N];
vector<int> adj[N];

void processLCA(int u, int p) {
    depth[u] = (u == p ? 0 : 1 + depth[p]);
    up[u][0] = p; tin[u] = ++tim;
    for (int i = 1; i < L; i++)
        up[u][i] = up[up[u][i - 1]][i - 1];
    for (auto v : adj[u]) {
        if (v == p) continue;
        processLCA(v, u);
    }
    tout[u] = ++tim;
}

void dfs(int u, int p) {
    dp[u] = 1LL * a[u] * a[u] + (u == p ? 0 : dp[p]);
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
    }
}

bool is_anc(int u, int v) { return (tin[u] <= tin[v] && tout[u] >= tout[v]); }

int LCA(int u, int v) {
    if (is_anc(u, v)) return u;
    if (is_anc(v, u)) return v;
    for (int i = L - 1; i >= 0; i--) {
        if (!is_anc(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

int distance(int u, int v) {
    int w = LCA(u, v);
    return depth[u] + depth[v] - 2 * depth[w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    in(n), in(q);
    for (int i = 1; i <= n; i++) {
        in(a[i]);
    }
    vector<int> p(n + 1);
    for (int i = 2; i <= n; i++) {
        in(p[i]);
        adj[i].emplace_back(p[i]);
        adj[p[i]].emplace_back(i);
    }
    processLCA(1, 1);
    dfs(1, 1);
    vector<tuple<int, int, int, int>> qr(q);
    for (int it = 0; it < q; it++) {
        int u, v;
        in(u), in(v);
        qr[it] = make_tuple(depth[u], u, v, it);
    }
    sort(qr.begin(), qr.end());
    vector<long long> ans(q);
    map<pair<int, int>, int> mp;
    for (int it = 0; it < q; it++) {
        auto [_, u, v, i] = qr[it];
        int cu = u, cv = v;
        long long cur = 0;
        while (u > 0 && v > 0) {
            if (u == v) {
                cur += dp[u];
                break;
            } else {
                int x = min(u, v);
                int y = max(u, v);
                pair<int, int> pr = make_pair(x, y);
                if (mp.count(pr) > 0) {
                    cur += ans[mp[pr]];
                    break;
                }
                cur += 1LL * a[u] * a[v];
                u = p[u], v = p[v];
            }
        }
        int x = min(cu, cv);
        int y = max(cu, cv);
        mp[make_pair(x, y)] = i;
        ans[i] = cur;
    }
    for (int i = 0; i < q; i++) {
        out(ans[i], '\n');
    }
    
    return 0;
}