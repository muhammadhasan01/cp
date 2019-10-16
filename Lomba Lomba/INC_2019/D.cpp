#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, m, q;
vector<int> g[N];
short int vis[N];
int par[N], sz[N], parz[N];
deque<int> dq;

int fpar(int x) {
    if (par[x] == x) return x;
    return par[x] = fpar(par[x]);
}

bool merge(int u, int v) {
    int pu = fpar(u);
    int pv = fpar(v);
    if (pu == pv) return true;
    if (sz[pu] < sz[pv]) swap(pu, pv);
    sz[pu] += sz[pv];
    par[pv] = pu;
    return false;
}

void dfs(int u, int p) {
    //cerr << u << '\n';
    dq.push_front(u);
    vis[u] = 1;
    for (auto e : g[u]) {
        if (e == p) continue;
        if (vis[e] == 0) {
            dfs(e, u);
        } else if (vis[e] == 1) {
            // cerr << "Cycle founded : " << u << " " << e << "\n";
            int p1 = fpar(e);
            // cerr << p1 << '\n';
            for (auto el : dq) {
                // cerr << "Merged : " << fpar(el) << " " << u << '\n';
                int p2 = fpar(el);
                if (p2 == p1) {
                    merge(p1, u);
                    break;
                } else {
                    merge(p2, u);
                }
            }
            cerr << '\n';
        }
    }
    dq.pop_front();
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] != 2) {
            dfs(i, i);
        }
    }

    for (int i = 1; i <= n; i++) {
        parz[i] = fpar(i);
        //cerr << i << " => " << fpar(i) << '\n';
    }

    for (int i = 1; i <= q; i++) {
        int u, v;
        cin >> u >> v;
        cout << (parz[u] == parz[v] ? "YES" : "NO") << '\n';
    }

    return 0;
}
