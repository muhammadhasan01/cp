#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

template<typename T = ordered_set>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

    void add(int x, int val) {
        for ( ; x <= n; x += x & -x)
            bit[x].insert(val);
    }

    void erase(int x, int val) {
        for ( ; x <= n; x += x & -x) {
            bit[x].erase(val);
        }
    }

    int get(int x, int l, int r) {
        int ret = 0;
        for ( ; x > 0; x -= x & -x)
            ret += bit[x].order_of_key(r + 1) - bit[x].order_of_key(l);
        return ret;
    }

    int query(int l, int r, int x, int y) {
        return get(r, x, y) - get(l - 1, x, y);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> p(n + 1);
    BIT<ordered_set> bit(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        p[a[i]] = i;
    }
    vector<int> b(n + 1);
    vector<int> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        pos[b[i]] = i;
    }
    vector<int> val(n + 1);
    for (int i = 1; i <= n; i++) {
        val[i] = pos[a[i]];
    }
    vector<int> id(n + 1);
    for (int i = 1; i <= n; i++) {
        id[i] = p[b[i]];
    }
    auto build = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            bit.add(i, val[i]);
        }
    };
    auto get_query = [&](int la, int ra, int lb, int rb) -> int {
        return bit.query(la, ra, lb, rb);
    };
    auto swap_pos = [&](int x, int y) -> void {
        int pos_x = id[x];
        int pos_y = id[y];
        bit.erase(pos_x, x);
        bit.erase(pos_y, y);
        bit.add(pos_x, y);
        bit.add(pos_y, x);
        pos[b[x]] = y;
        pos[b[y]] = x;
        val[pos_x] = y;
        val[pos_y] = x;
        id[x] = pos_y;
        id[y] = pos_x;
        swap(b[x], b[y]);
    };
    build();
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int la, ra, lb, rb;
            cin >> la >> ra >> lb >> rb;
            cout << get_query(la, ra, lb, rb) << '\n';
        } else if (tp == 2) {
            int x, y;
            cin >> x >> y;
            swap_pos(x, y);
        }
    }
    
    return 0;
}