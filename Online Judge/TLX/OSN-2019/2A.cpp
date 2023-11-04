#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, T val) {
        for ( ; x > 0; x -= x & -x)
            bit[x] += val;
    }

    T get(int x) {
        T ret = 0;
        for ( ; x <= n; x += x & -x)
            ret += bit[x];
        return ret;
    }

    T query(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> p(n);
    vector<int> vals;
    for (int i = 0; i < n; i++) {
        auto& [x, y, pos] = p[i];
        cin >> x >> y;
        pos = i;
        vals.emplace_back(x);
        vals.emplace_back(y);
    }
    sort(vals.begin(), vals.end());
    vals.resize(unique(vals.begin(), vals.end()) - vals.begin());
    int len = (int) vals.size();
    BIT<int> bit(len + 5);
    vector<int> ans(n);
    vector<vector<pair<int, int>>> query(n);
    sort(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        auto [x, y, pos] = p[i];
        int id = lower_bound(vals.begin(), vals.end(), y) - vals.begin() + 1;
        bit.add(id, 1);
        int at = -1;
        {
            int l = 0, r = n - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (get<0>(p[mid]) <= y) {
                    at = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        assert(at != -1);
        query[at].emplace_back(pos, x);
        for (auto [j, val] : query[i]) {
            int cur = lower_bound(vals.begin(), vals.end(), val) - vals.begin() + 1;
            ans[j] += bit.get(cur);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] - 1 << '\n';
    }

    return 0;
}