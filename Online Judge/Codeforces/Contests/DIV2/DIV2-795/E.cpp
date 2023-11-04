#include <bits/stdc++.h>

using namespace std;

const int K = 2;

struct DSU {
    int n;
    vector<int> par, sz;
    vector<vector<int>> vals;
    
    DSU(int t_n) : n(t_n), par(t_n), sz(t_n), vals(t_n, vector<int>(K, -1)) {
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
        for (int i = 0; i < K; i++) {
            vals[pu][i] = max(vals[pu][i], vals[pv][i]);
        }
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

template<typename T>
struct Compresser {
    vector<T> nums;
    
    Compresser() { }

    Compresser(vector<T>& v) {
        nums.assign(v.begin(), v.end());
        finish();
    }
 
    void add(T x) {
        nums.emplace_back(x);
    }
 
    void finish() {
        sort(nums.begin(), nums.end());
        nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    }
 
    int getId(T x) {
        return lower_bound(nums.begin(), nums.end(), x) - nums.begin() + 1;
    }

    T getValue(int id) {
        return nums[id - 1];
    }
 
    int getLen() {
        return nums.size();
    }
};

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> lines(n);
    for (auto& [l, r, c] : lines) {
        cin >> c >> l >> r;
    }
    Compresser<int> comp;
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        auto [l, r, c] = lines[i];
        dsu.vals[i][c] = r;
        for (int dif = -1; dif <= 1; dif++) {
            comp.add(l + dif);
            comp.add(r + dif);
        }
    }
    comp.finish();
    int len = comp.getLen();
    vector<vector<int>> in(len + 1);
    vector<vector<int>> out(len + 1);
    for (int i = 0; i < n; i++) {
        auto [l, r, c] = lines[i];
        in[comp.getId(l)].emplace_back(i);
        out[comp.getId(r)].emplace_back(i);
    }
    vector<set<pair<int, int>>> st(K);
    for (int pos = 1; pos <= len; pos++) {
        for (int i : in[pos]) {
            auto [l, r, c] = lines[i];
            int oc = 1 - c;
            while (true) {
                if (st[oc].empty()) {
                    break;
                }
                auto [_, idx] = *st[oc].begin();
                dsu.merge(i, idx);
                if ((int) st[oc].size() > 1) {
                    st[oc].erase(st[oc].begin());
                } else {
                    break;
                }
            }
            st[c].emplace(r, i);
        }
        for (int i : out[pos]) {
            auto [l, r, c] = lines[i];
            if (st[c].find({r, i}) == st[c].end()) {
                continue;
            }
            st[c].erase({r, i});
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == dsu.fpar(i)) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}