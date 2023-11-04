#include <bits/stdc++.h>

using namespace std;

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
        if (sz[pu] < sz[pv]) swap(pu, pv);
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, s, q;
    cin >> n >> s >> q;
    Compresser<int> comp;
    vector<vector<pair<int, int>>> ranges(n);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ranges[i].resize(t);
        for (auto& [l, r] : ranges[i]) {
            cin >> l >> r;
            for (int pos : {l - 1, l, l + 1, r - 1, r, r + 1}) {
                comp.add(pos);
            }
        }
    }
    comp.finish();
    int len = comp.getLen();
    vector<vector<int>> in(len + 1), out(len + 1);
    for (int i = 0; i < n; i++) {
        for (auto& [l, r] : ranges[i]) {
            l = comp.getId(l);
            r = comp.getId(r);
            in[l].emplace_back(i);
            out[r].emplace_back(i);
        }
    }
    set<int> st;
    DSU dsu(n);
    for (int i = 1; i <= len; i++) {
        for (int j : in[i]) {
            if (!st.empty()) {
                dsu.merge(*st.begin(), j);
            }
            st.emplace(j);
        }
        for (int j : out[i]) {
            st.erase(j);
        }
    }
    while (q--) {
        int p;
        cin >> p;
        --p;
        cout << dsu.getSize(p) << '\n';
    }
    
    return 0;
}