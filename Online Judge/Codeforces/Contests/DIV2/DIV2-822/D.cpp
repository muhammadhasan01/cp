#include <bits/stdc++.h>

using namespace std;
using pll = pair<long long, long long>;

const long long INF = 1e18;

struct SparseTable {
    int n;
    vector<vector<pll>> dp;
    vector<int> prec;

    SparseTable(vector<long long>& a) {
        n = a.size();
        int len = 1;
        int k = 0;
        while (len <= 2 * n) {
            len <<= 1;
            ++k;
        }
        dp.assign(len, vector<pll>(k, {INF, -INF}));
        prec.assign(len, 0);
        for (int i = 2; i < 2 * n; i++) {
            prec[i] = prec[i >> 1] + 1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][0] = {a[i], a[i]};
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = combine(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    pll combine(const pll& a, const pll& b) {
        return {min(a.first, b.first), max(a.second, b.second)};
    }

    pll query(int l, int r) {
        int k = prec[r - l + 1];
        return combine(dp[l][k], dp[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 3);
    for (int i = 2; i <= n + 1; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n + 3);
    map<long long, set<int>> mp;
    mp[pre[0]].emplace(0);
    for (int i = 1; i <= n + 2; i++) {
        pre[i] = pre[i - 1] + a[i];
        mp[pre[i]].emplace(i);
    }
    SparseTable sp(pre);
    long long health = a[++k];
    int posL = k, posR = k;
    while (1) {
        int L = -1;
        {
            int l = 1, r = posL - 1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (health + pre[posL - 1] - sp.query(mid - 1, posL - 2).second >= 0) {
                    r = mid - 1;
                    L = mid;
                } else {
                    l = mid + 1;
                }
            }
        }
        int R = -1;
        {
            int l = posR + 1, r = n + 2;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (health + sp.query(posR + 1, mid).first - pre[posR] >= 0) {
                    l = mid + 1;
                    R = mid;
                } else {
                    r = mid - 1;
                }
            }
        }
        if (L == 1 || R == n + 2) {
            cout << "YES" << '\n';
            return;
        }

        auto getOptimalLeft = [&]() -> pair<int, long long> {
            if (L == -1) {
                return {L, -INF};
            }
            long long val = sp.query(L - 1, posL - 2).first;
            return {*mp[val].lower_bound(L - 1), pre[posL - 1] - val};
        };

        auto getOptimalRight = [&]() -> pair<int, long long> {
            if (R == -1) {
                return {R, -INF};
            }
            long long val = sp.query(posR + 1, R).second;
            return {*mp[val].lower_bound(posR + 1), val - pre[posR]};
        };

        auto [optL, valL] = getOptimalLeft();
        auto [optR, valR] = getOptimalRight();
        if (valL > valR) {
            health += valL;
            posL = optL + 1;
        } else {
            health += valR;
            posR = optR;
        }
        if (health < 0) {
            cout << "NO" << '\n';
            return;
        }
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