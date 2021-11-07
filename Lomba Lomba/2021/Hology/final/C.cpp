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
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    BIT<int> bit(n * n + 5);
    long long inv = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                continue;
            }
            inv += bit.get(a[i][j] + 1);
            bit.add(a[i][j], 1);
        }
    }
    if (n % 2 == 1) {
        cout << (inv % 2 == 0 ? "YA" : "TIDAK") << '\n';
    } else {
        int pos = -1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (a[i][j] == 0) {
                    pos = n - i;
                }
            }
        }
        cout << (inv % 2 != pos % 2 ? "YA" : "TIDAK") << '\n';
    }
    
    
    return 0;
}