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

const int K = 50;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    int m = n + q + 5;
    BIT<int> bit(m);
    vector<int> pos(K + 1, -1);
    for (int i = 1; i <= n; i++) {
        int id = i + q;
        bit.add(id, 1);
        int x;
        cin >> x;
        if (pos[x] == -1) {
            pos[x] = id;
        }
    }
    int cur = q;
    for (int it = 0; it < q; it++) {
        int t;
        cin >> t;
        cout << n - bit.get(pos[t]) + 1 << " \n"[it == q - 1];
        bit.add(pos[t], -1);
        pos[t] = cur--;
        bit.add(pos[t], 1);
    }
    
    return 0;
}