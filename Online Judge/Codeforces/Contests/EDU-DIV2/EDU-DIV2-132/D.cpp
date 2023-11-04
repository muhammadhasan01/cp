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
        while (len < 2 * n) {
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
        return max(a, b);
    }

    T query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    SparseTable<int> sp(a);

    auto answerQuery = [&](int sx, int sy, int ex, int ey, int k) -> void {
        int dx = abs(sx - ex);
        if (dx % k != 0) {
            cout << "NO" << '\n';
            return;
        }
        int dy = abs(sy - ey);
        if (dy % k != 0) {
            cout << "NO" << '\n';
            return;
        }
        int highest = n - (n - sx) % k;
        if (sy > ey) {
            swap(sy, ey);
        }
        int largest = sp.query(sy, ey);
        if (largest >= highest) {
            cout << "NO" << '\n';
            return;
        }
        cout << "YES" << '\n';
    };

    int q;
    cin >> q;
    while (q--) {
        int sx, sy, ex, ey, k;
        cin >> sx >> sy >> ex >> ey >> k;
        answerQuery(sx, sy, ex, ey, k);
    }
    
    return 0;
}