#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> pos = {0}, neg = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 0) {
            pos.emplace_back(x);
        } else if (x < 0) {
            neg.emplace_back(-x);
        }
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    auto getAns = [&](vector<int>& v) -> pair<long long, long long> {
        int m = (int) v.size();
        vector<vector<long long>> dp(m, vector<long long>(2, INF));
        dp[0][0] = 0;
        dp[0][1] = 0;
        set<pair<long long, int>> st;
        st.emplace(dp[0][1], 0);
        for (int i = 1; i < m; i++) {
            dp[i][0] = st.begin()->first + v[i];
            dp[i][1] = dp[i][0] + v[i];
            st.emplace(dp[i][1], i);
            if (i - k >= 0) {
                st.erase({dp[i - k][1], i - k});
            }
        }
        return {dp[m - 1][0], dp[m - 1][1]};
    };

    auto [p0, p1] = getAns(pos);
    auto [n0, n1] = getAns(neg);

    cout << min(p0 + n1, p1 + n0) << '\n';
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