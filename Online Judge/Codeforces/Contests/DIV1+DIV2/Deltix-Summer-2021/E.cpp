#include <bits/stdc++.h>

using namespace std;

template<int MAXN, int MAXLOG, typename T = pair<long long, long long>>
struct sparse_table {
    int n;
    vector<vector<T>> dp;
    vector<int> prec_lg2;

    sparse_table() {
        dp.assign(MAXN, vector<T>(MAXLOG, make_pair(0, 0)));
        prec_lg2.assign(MAXN, 0);
    }

    T combine(const T& a, const T& b) {
        return make_pair(min(a.first, b.first), max(a.second, b.second));
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

sparse_table<N, L, pair<long long, long long>> sp;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<long long, long long>> p(n + 1);
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] = x - a[i];
        pre[i] = pre[i - 1] + a[i];
        p[i] = make_pair(pre[i], pre[i]);
    }
    sp.init(p);
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (pre[r] - pre[l - 1] != 0) {
            cout << -1 << '\n';
            continue;
        }
        auto [mini, maxi] = sp.query(l, r);
        if (mini < pre[l - 1]) {
            cout << -1 << '\n';
            continue;
        }
        cout << maxi - pre[l - 1] << '\n';
    }
    
    return 0;
}