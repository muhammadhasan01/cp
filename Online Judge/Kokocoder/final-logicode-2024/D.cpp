#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct SparseTable {
    vector<vector<T>> sp;
    vector<int> prec;

    SparseTable(vector<T>& a) {
        int n = (int) a.size();
        int lg = __lg(n) + 1;
        sp.resize(n, vector<T>(lg));
        for (int i = 0; i < n; i++) {
            sp[i][0] = a[i];
        }
        for (int j = 0; j < lg - 1; j++) {
            for (int i = 0; i < n; i++) {
                if (i + (1 << (j + 1)) > n) {
                    break;
                }
                sp[i][j + 1] = combine(sp[i][j], sp[i + (1 << j)][j]);
            }
        }
    }

    T combine(const T& a, const T& b) {
        return (a | b);
    }

    T get(int l, int r) {
        int k = __lg(r - l + 1);
        return combine(sp[l][k], sp[r - (1 << k) + 1][k]);
    }
};

template<typename T>
struct BIT {
    int n;
    vector<T> bit;
    
    BIT(int t_n) : n(t_n), bit(t_n + 1) {}

    void add(int x, T val) {
        for ( ; x <= n; x += x & -x) {
            bit[x] = max(bit[x], val);
        }
    }

    T get(int x) {
        T ret = 0;
        for ( ; x > 0; x -= x & -x) {
            ret = max(ret, bit[x]);
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    vector<vector<pair<int, int>>> L(n + 1);
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        L[r].emplace_back(l, i);
    }
    for (int i = 1; i <= n; i++) {
        if ((a[i] | x) > x) {
            a[i] = 0;
        }
    }
    SparseTable<int> sp(a);
    vector<int> f(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sp.get(i, mid) == x) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at != -1) {
            f[i] = at - i + 1;
        }
    }
    BIT<int> bit(n + 1);
    vector<vector<pair<int, int>>> add(n + 1);
    vector<int> ans(q + 1, -1);

    auto getAns = [&](int lft) -> int {
        int l = 1, r = n, ret = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (bit.get(mid) >= lft) {
                r = mid - 1;
                ret = mid;
            } else {
                l = mid + 1;
            }
        }
        return ret;
    };

    for (int r = 1; r <= n; r++) {
        if (f[r] != -1) {
            add[r + f[r] - 1].emplace_back(f[r], r);
        }
        for (auto [len, pos] : add[r]) {
            bit.add(len, pos);
        }
        for (auto [l, i] : L[r]) {
            ans[i] = getAns(l);
        }
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
    
    return 0;
}