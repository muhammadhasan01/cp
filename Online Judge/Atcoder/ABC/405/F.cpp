#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int t_n) : n(t_n), bit(t_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        if (l > r) {
            return 0;
        }
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int len = 2 * n;
    vector<int> val(len + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        val[a] = b;
        val[b] = a;
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    vector<vector<pair<int, int>>> events(len + 1);
    for (int i = 0; i < q; i++) {
        int c, d;
        cin >> c >> d;
        queries[i] = {c, d};
        events[c].emplace_back(i, -1);
        events[d].emplace_back(i, 1);
    }
    vector<int> ans(q);
    BIT<int> bit(len);
    for (int x = 1; x <= len; x++) {
        if (val[x] > 0) {
            bit.add(val[x], 1);
        }
        for (auto [idx, op] : events[x]) {
            auto [c, d] = queries[idx];
            int cur = bit.query(1, c) + bit.query(d, len);
            ans[idx] += cur * op;
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
    
    return 0;
}