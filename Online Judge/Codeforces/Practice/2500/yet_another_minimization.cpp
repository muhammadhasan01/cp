#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> dp(n), ndp(n);
    long long cost = 0;
    int L = 1, R = 0;
    vector<int> occ(n + 1);
    auto C = [&](int l, int r) -> long long {
        while (r > R) {
            R++;
            cost += occ[a[R]]++;
        }
        while (l < L) {
            L--;
            cost += occ[a[L]]++;
        }
        while (r < R) {
            cost -= --occ[a[R]];
            R--;
        }
        while (l > L) {
            cost -= --occ[a[L]];
            L++;
        }
        return cost;
    };
    function<void(int, int, int, int)> DnC = [&](int l, int r, int optl, int optr) {
        if (l > r) {
            return;
        }
        int mid = (l + r) >> 1;
        pair<long long, int> best = make_pair(INF, -1);
        for (int i = optl; i <= min(optr, mid); i++) {
            long long cur = (i == 0 ? 0 : dp[i - 1]) + C(i, mid);
            best = min(best, {cur, i});
        }
        auto [val, opt] = best;
        ndp[mid] = val;
        DnC(l, mid - 1, optl, opt);
        DnC(mid + 1, r, opt, optr);
    };
    for (int i = 0; i < n; i++) {
        dp[i] = C(0, i);
    }
    for (int i = 1; i < k; i++) {
        DnC(0, n - 1, 0, n - 1);
        dp = ndp;
    }
    cout << dp[n - 1] << '\n';

    return 0;
}