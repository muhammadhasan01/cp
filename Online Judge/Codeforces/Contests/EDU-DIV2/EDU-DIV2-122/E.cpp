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

    int getSize(int x) {
        int px = fpar(x);
        return sz[px];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> u(m), v(m), w(m);
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
    }
    vector<int> weights = {0};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            int mid = (w[i] + w[j] + 1) / 2;
            weights.emplace_back(mid);
            weights.emplace_back(mid + 1);
        }
    }
    sort(weights.begin(), weights.end());
    weights.erase(unique(weights.begin(), weights.end()), weights.end());
    int len = weights.size();
    vector<long long> dp(len);
    vector<int> dif(len);
    for (int i = 0; i < len; i++) {
        vector<pair<int, int>> E(m);
        for (int j = 0; j < m; j++) {
            E[j] = {abs(w[j] - weights[i]), j};
        }
        DSU dsu(n + 1);
        sort(E.begin(), E.end());
        int cnt = 0;
        for (auto& [cw, id] : E) {
            int pu = dsu.fpar(u[id]);
            int pv = dsu.fpar(v[id]);
            if (pu == pv) {
                continue;
            }
            ++cnt;
            dsu.merge(pu, pv);
            dp[i] += cw;
            dif[i] += (weights[i] >= w[id] ? 1 : -1);
            if (cnt == n - 1) {
                break;
            }
        }
    }

    auto getAnswer = [&](int x) -> long long {
        int pos = upper_bound(weights.begin(), weights.end(), x) - weights.begin() - 1;
        return dp[pos] + 1LL * (x - weights[pos]) * dif[pos];
    };

    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;
    long long ans = 0;
    int x;
    for (int i = 1; i <= p; i++) {
        cin >> x;
        ans ^= getAnswer(x);
    }
    for (int i = p + 1; i <= k; i++) {
        x = (1LL * x * a + b) % c;
        ans ^= getAnswer(x);
    }
    cout << ans << '\n';
    
    return 0;
}