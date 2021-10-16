#include <bits/stdc++.h>

using namespace std;

struct DSU {
    int n;
    vector<int> par, sz;
    
    DSU(int _n) : n(_n), par(_n), sz(_n) {
        iota(par.begin(), par.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    }

    int fpar(int x) {
        return (par[x] == x ? x : fpar(par[x]));
    }

    bool merge(int u, int v) {
        int pu = fpar(u), pv = fpar(v);
        if (pu == pv) return false;
        if (sz[pu] < sz[pv]) swap(pu, pv);
        par[pv] = pu;
        sz[pu] += sz[pv];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    vector<vector<pair<int, int>>> comment(n + 1);
    vector<vector<pair<int, int>>> rcomment(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        dsu.merge(u, v);
        int cc = (s[0] == 'i');
        comment[u].emplace_back(v, cc);
        rcomment[v].emplace_back(u, cc);
    }
    vector<vector<int>> comp(n + 1);
    for (int u = 1; u <= n; u++) {
        comp[dsu.fpar(u)].emplace_back(u);
    }
    int ans = 0;
    vector<int> state(n + 1);
    for (int u = 1; u <= n; u++) {
        if (comp[u].empty()) {
            continue;
        }
        int len = comp[u].size();
        if (len == 1) {
            ans += 1;
            continue;
        }
        vector<int> res(2);
        for (int it = 0; it < 2; it++) {
            for (int x : comp[u]) {
                state[x] = -1;
            }
            int s = comp[u][0];
            state[s] = it;
            int& ret = res[it];
            queue<int> q;
            q.emplace(s);
            while (!q.empty()) {
                if (ret == -1) {
                    break;
                }
                int x = q.front();
                q.pop();
                for (auto [y, cc] : comment[x]) {
                    int cstate = (cc ^ state[x]);
                    if (state[y] == -1) {
                        state[y] = cstate;
                        q.emplace(y);
                    } else {
                        if (state[y] != cstate) {
                            ret = -1;
                            break;
                        }
                    }
                }
                for (auto [y, cc] : rcomment[x]) {
                    int cstate = (cc != state[x]);
                    if (state[y] == -1) {
                        state[y] = cstate;
                        q.emplace(y);
                    } else {
                        if (state[y] != cstate) {
                            ret = -1;
                            break;
                        }
                    }
                }
            }
            if (ret == -1) {
                continue;
            }
            for (int x : comp[u]) {
                if (state[x] == 1) {
                    ret++;   
                }
            }
        }
        if (res[0] == -1 || res[1] == -1) {
            cout << -1 << '\n';
            return;
        }
        ans += max(res[0], res[1]);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}