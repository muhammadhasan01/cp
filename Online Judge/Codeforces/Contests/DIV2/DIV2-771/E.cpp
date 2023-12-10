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
    
    int n, q;
    cin >> n >> q;
    BIT<long long> bit(n + 5);
    vector<long long> col(n + 1);
    map<long long, int> mp;
    mp[1] = 1;
    mp[n + 1] = 1;

    auto cut = [&](int x) -> void {
        if (mp.find(x) == mp.end()) {
            mp[x] = prev(mp.lower_bound(x))->second;
        }
    };

    while (q--) {
        string op;
        cin >> op;
        if (op == "Color") {
            int l, r, c;
            cin >> l >> r >> c;
            r++;
            cut(l);
            cut(r);
            auto it = mp.find(l);
            while (it->first < r) {
                auto nxt = next(it);
                int L = it->first;
                int R = nxt->first;
                long long dif = col[it->second] - col[c];
                bit.add(L, dif);
                bit.add(R, -dif);
                it = mp.erase(it);
            }
            mp[l] = c;
        } else if (op == "Add") {
            int c, x;
            cin >> c >> x;
            col[c] += x;
        } else if (op == "Query") {
            int i;
            cin >> i;
            cut(i);
            int c = mp[i];
            cout << col[c] + bit.get(i) << '\n';
        }
    }
    
    return 0;
}