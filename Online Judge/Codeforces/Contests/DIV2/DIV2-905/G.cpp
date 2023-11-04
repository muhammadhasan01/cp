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
        return get(r) - get(l - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (auto& [l, r] : queries) {
        cin >> l >> r;
    }
    set<int> high = {0};
    set<int> low;
    for (int i = 1; i <= n + 1; i++) {
        low.emplace(i);
    }
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[a[i]] = i;
    }
    vector<tuple<int, int, int, int, int>> events;
    for (int x = n; x >= 1; x--) {
        high.emplace(pos[x]);
        low.erase(pos[x]);
        if (high.upper_bound(pos[x]) == high.end()) {
            continue;
        }
        int R1 = *high.upper_bound(pos[x]);
        int R2 = *low.upper_bound(R1) - 1;
        int L1 = *prev(high.lower_bound(pos[x])) + 1;
        int L2 = pos[x];
        events.emplace_back(L1, 0, R1, R2, -1);
        events.emplace_back(L2, 2, R1, R2, -1);
    }
    for (int i = 0; i < q; i++) {
        auto& [l, r] = queries[i];
        events.emplace_back(l, 1, r, r, i);
    }
    BIT<int> bit(n + 5);
    vector<bool> ans(q);
    sort(events.begin(), events.end());
    for (auto& [l, tp, r1, r2, idx] : events) {
        if (tp == 0) {
            bit.add(r1, 1);
            bit.add(r2 + 1, -1);
        } else if (tp == 1) {
            ans[idx] = bit.get(r1) > 0;
        } else if (tp == 2) {
            bit.add(r1, -1);
            bit.add(r2 + 1, 1);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "Yes" : "No") << '\n';
    }

    return 0;
}