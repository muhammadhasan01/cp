#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int _n) : n(_n), bit(_n + 1) {}

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
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    BIT<int> row(n + 5), col(n + 5);
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int b, x;
            cin >> b >> x;
            if (x % 2 == 0) {
                continue;
            }
            row.add(b, 1);
        } else if (tp == 2) {
            int k, x;
            cin >> k >> x;
            if (x % 2 == 0) {
                continue;
            }
            col.add(k, 1);
        } else if (tp == 3) {
            int b1, b2, k1, k2;
            cin >> b1 >> k1 >> b2 >> k2;
            int ans = 0;
            // check for column
            int len_b = b2 - b1 + 1;
            if (len_b % 2 == 1) {
                int res = col.query(k1, k2) % 2;
                ans = (ans + res) % 2;
            }
            // check for row
            int len_k = k2 - k1 + 1;
            if (len_k % 2 == 1) {
                int res = row.query(b1, b2) % 2;
                ans = (ans + res) % 2;
            }
            cout << (ans % 2 == 0 ? "Genap" : "Ganjil") << '\n';
        }
    }
    
    return 0;
}