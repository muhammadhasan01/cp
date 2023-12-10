#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int t_n) : n(t_n), bit(t_n + 1) {}

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n < 3) {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << '\n';
        return;
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (++cnt[a[i]] > 1) {
            cout << "YES" << '\n';
            return;
        }
    }
    BIT<int> bit(n + 5);
    int parity = 0;
    for (int i = 0; i < n; i++) {
        parity ^= bit.get(a[i] + 1);
        bit.add(a[i], 1);
    }
    cout << (parity % 2 == 0 ? "YES" : "NO") << '\n';
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