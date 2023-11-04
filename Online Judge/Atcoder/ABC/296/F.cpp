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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    BIT<int> A(n + 5);
    int parity = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        parity = (parity ^ (A.get(a[i] + 1) & 1));
        A.add(a[i], 1);
    }
    vector<int> b(n);
    BIT<int> B(n + 5);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        parity = (parity ^ (B.get(b[i] + 1) & 1));
        B.add(b[i], 1);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (a != b) {
        cout << "No" << '\n';
        return 0;
    }
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << (parity == 0 ? "Yes" : "No") << '\n';
    
    return 0;
}