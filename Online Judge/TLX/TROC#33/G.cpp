#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

struct SparseTable {
    int n;
    vector<vector<long long>> dp;
    vector<int> prec;

    SparseTable(vector<long long>& a) {
        n = a.size();
        int len = 1;
        int k = 0;
        while (len <= 2 * n) {
            len <<= 1;
            ++k;
        }
        dp.assign(len, vector<long long>(k, 1LL));
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

    long long combine(long long a, long long b) {
        long long g = __gcd(a, b);
        a /= g;
        if (a >= INF / b) {
            return INF;
        }
        return a * b;
    }

    long long query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        p[i]--;
    }
    sort(p.begin(), p.end());
    SparseTable sp(a);

    map<pair<int, int>, long long> memo;
    function<long long(int, int)> getMin = [&](int L, int R) {
        if (memo.count({L, R})) {
            return memo[{L, R}];
        }
        if (L >= R) {
            return 0LL;
        }
        if (L + 1 == R) {
            return sp.query(L, R);
        }
        int rgt = L + 1;
        long long ans = INF;
        while (rgt <= R) {
            long long cur = sp.query(L, rgt);
            if (cur == INF) {
                break;
            }
            int l = rgt, r = R, at = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sp.query(L, mid) <= cur) {
                    l = mid + 1;
                    at = mid;
                } else {
                    r = mid - 1;
                }
            }
            assert(at != -1);
            ans = min(ans, cur + getMin(at, R));
            rgt = at + 1;
        }
        return memo[{L, R}] = ans;
    };

    long long ans = 0;
    for (int i = 0; i < k - 1; i++) {
        ans += getMin(p[i], p[i + 1]);
    }
    cout << ans << '\n';
    
    return 0;
}