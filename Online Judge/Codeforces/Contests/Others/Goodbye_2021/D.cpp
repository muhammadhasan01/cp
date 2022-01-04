#include <bits/stdc++.h>

using namespace std;

template<int MAXN, int MAXLOG, typename T>
struct sparse_table {
    int n;
    vector<vector<T>> dp;
    vector<int> prec_lg2;

    sparse_table() {
        dp.assign(MAXN, vector<T>(MAXLOG, 0));
        prec_lg2.assign(MAXN, 0);
    }

    T combine(const T& a, const T& b) {
        return max(a, b);
    }

    void init(vector<T> &a) {
        n = a.size();
        for (int i = 2; i < 2 * n; i++) {
            prec_lg2[i] = prec_lg2[i >> 1] + 1;
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

    T query(int l, int r) {
        int k = prec_lg2[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

const int L = 18;
const int N = (1 << L);

sparse_table<N, L, long long> sp;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long x;
    cin >> x;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i] - x;
        a[i] += a[i - 1];
    }
    sp.init(a);
    vector<int> dp(n + 1);
    vector<int> lft(n + 1);
    dp[1] = lft[1] = 1;
    for (int i = 2; i <= n; i++) {
        int l = 0, r = i - 2, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sp.query(mid, i - 2) <= a[i]) {
                r = mid - 1;
                at = mid + 1;
            } else {
                l = mid + 1;
            }
        }
        lft[i] = i;
        if (at != -1) {
            lft[i] = max(lft[i - 1], at);
            dp[i] = i - lft[i] + 1;
            if (lft[i] - 2 >= 0) {
                dp[i] += dp[lft[i] - 2];
            }
        }
        dp[i] = max(dp[i], 1 + dp[i - 2]);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}