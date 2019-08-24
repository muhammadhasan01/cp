#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 5;
int n, m;
short int vis[N];
vector<int> g[N];
vector<pair<int,int>> cycles, store;
int pu, pv;

bool fcycle(int u, int p) {
    store.push_back({p, u});
    if (vis[u] == 1) {
        int j = store.size() - 1;
        while (store[j].first != u) j--;
        for (int i = j; i < store.size(); i++) cycles.push_back(store[i]);
        return true;
    } else if (vis[u] == 2) {
        return false;
    }
    vis[u] = 1;
    for (auto e : g[u]) {
        if (fcycle(e, u)) {
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

bool check(int u) {
    vis[u] = 1;
    bool ok = false;
    for (auto e : g[u]) {
        if (u == pu && e == pv) continue;
        if (vis[e] == 0) {
            ok |= check(e);
        } else if (vis[e] == 1){
            return true;
        }
        if (ok) return ok;
    }
    vis[u] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
        if (fcycle(i, 0)) {
            flag = true;
            break;
        }
    }

    for (auto e : cycles) {
        cerr << e.first << " " << e.second << '\n';
    }

    if (!flag) {
        puts("YES");
        return 0;
    }

    for (auto e : cycles) {
        pu = e.first, pv = e.second;
        for (int i = 1; i <= n; i++) vis[i] = 0;
        bool cek = false;
        for (int i = 1; i <= n; i++) {
            if (check(i)) {
                cek = true;
                break;
            }
        }
        if (!cek) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
