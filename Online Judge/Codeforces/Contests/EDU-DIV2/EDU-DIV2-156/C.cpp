#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (pu > pv) {
            swap(pu, pv);
        }
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }

    bool isSameParent(int u, int v) {
        return fpar(u) == fpar(v);
    }

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};

void solve() {
    string s;
    cin >> s;
    int n = (int) s.length();
    s = "#" + s + "#";
    long long pos;
    cin >> pos;
    int it = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] > s[i + 1]) {
            it = i + 1;
            break;
        }
    }
    assert(it != -1);
    DSU dsu(n + 5);
    vector<bool> vis(n + 5);
    int len = n;
    while (pos - len > 0) {
        pos -= len;
        len--;
        int lft = dsu.fpar(it - 1);
        vis[lft] = true;
        if (lft >= 1) {
            dsu.merge(lft - 1, lft);
        }
        while (s[dsu.fpar(it - 1)] <= s[it]) {
            ++it;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            continue;
        }
        if (--pos == 0) {
            cout << s[i];
            return;
        }
    }
    assert(false);
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    cout << '\n';
    
    return 0;
}