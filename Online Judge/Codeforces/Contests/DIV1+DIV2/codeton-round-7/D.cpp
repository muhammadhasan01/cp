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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    BIT<int> bit(n + 5);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bit.add(i, a[i]);
        if (a[i] == 1) {
            st.emplace(i);
        }
    }

    auto check = [&](int l, int r) -> bool {
        auto it = st.lower_bound(l);
        return it != st.end() && *it <= r;
    };

    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int s;
            cin >> s;
            int l = 1, r = n, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (bit.get(mid) >= s) {
                    r = mid - 1;
                    at = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (at == -1) {
                cout << "NO" << '\n';
                continue;
            }
            if (bit.get(at) == s) {
                cout << "YES" << '\n';
                continue;
            }
            if (check(at, n) || check(1, n - at + 1)) {
                cout << "YES" << '\n';
                continue;
            }
            cout << "NO" << '\n';
        } else if (tp == 2) {
            int i, v;
            cin >> i >> v;
            if (a[i] == v) {
                continue;
            }
            bit.add(i, -a[i]);
            if (a[i] == 1) {
                st.erase(i);
            } else {
                st.emplace(i);
            }
            a[i] = v;
            bit.add(i, a[i]);
        }
    }
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