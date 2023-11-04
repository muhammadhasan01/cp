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

const int N = 1e5 + 10;
const int L = 17;

int up[N][L];
int depth[N], tin[N], tout[N], tim;
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
    
    int n;
    in(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        in(u), in(v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);    
    }
    processLCA(1, 1);
    int q;
    in(q);
    while (q--) {
        int k;
        in(k);
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            in(a[i]);
        }
        if (k == 1) {
            out(0, '\n');
            continue;
        }
        long long ans = 1e18;
        set<int> st;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                int cur = LCA(a[i], a[j]);
                if (st.count(cur)) {
                    continue;
                }
                st.emplace(cur);
                long long res = 0;
                for (int x = 0; x < k; x++) {
                    res += distance(a[x], cur);
                }
                ans = min(ans, res);
            }
        }
        out(ans, '\n');
    }
    
    return 0;
}