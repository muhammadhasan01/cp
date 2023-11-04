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
        if (par[x] == x) {
            return x;
        }
        return par[x] = fpar(par[x]);
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

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<pair<long long, long long>> p(n);
    for (auto& [x, y] : p) {
        cin >> x >> y;
    }

    auto can = [&](long long dist) {
        DSU dsu(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long dx = abs(p[i].first - p[j].first);
                long long dy = abs(p[i].second - p[j].second);
                long long cur = dx * dx + dy * dy;
                if (cur <= dist) {
                    dsu.merge(i, j);
                }
            }
        }
        return dsu.sz[0] == n;
    };

    long long l = 0, r = INF, ans = -1;
    while (l <= r) {
        long long mid = l + (r - l) / 2;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}