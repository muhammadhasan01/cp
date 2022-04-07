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
        return min(a, b);
    }

    void build(vector<T> &a) {
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

sparse_table<N, L, int> sp;


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        a[i] -= (i + 1);
    }
    sp.build(a);
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, at = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sp.query(i, mid) >= -i) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, at - i + 1);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
    
    return 0;
}