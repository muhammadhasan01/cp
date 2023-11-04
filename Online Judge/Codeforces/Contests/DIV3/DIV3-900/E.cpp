#include <bits/stdc++.h>

using namespace std;

template<typename T>
struct SparseTable {
    int n;
    vector<vector<T>> dp;
    vector<int> prec;

    SparseTable(vector<T>& a) {
        n = a.size();
        int len = 1;
        int k = 0;
        while (len <= 2 * n) {
            len <<= 1;
            ++k;
        }
        dp.assign(len, vector<T>(k, 0));
        prec.assign(len, 0);
        for (int i = 2; i < 2 * n; i++) {
            prec[i] = prec[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = a[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = combine(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T combine(const T& a, const T& b) {
        return (a & b);
    }

    T query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SparseTable<int> sp(a);
    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        --x;
        int l = x, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sp.query(x, mid) >= k) {
                l = mid + 1;
                at = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << at << '\n';
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