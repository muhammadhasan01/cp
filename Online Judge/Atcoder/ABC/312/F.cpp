#include <bits/stdc++.h>
 
using namespace std;
 
const long long INF = 1e18;
const int K = 3;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> X(K);
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        X[t].emplace_back(x);
    }
 
    auto getDp = [&](vector<int>& x) -> vector<long long> {
        sort(x.rbegin(), x.rend());
        vector<long long> dp(m + 1, -INF);
        dp[0] = 0;
        int len = (int) x.size();
        for (int i = 0; i < min(len, m); i++) {
            dp[i + 1] = dp[i] + x[i];
        }
        for (int i = len + 1; i <= m; i++) {
            dp[i] = dp[i - 1];
        }
        return dp;
    };
 
    vector<long long> R = getDp(X[0]);
    vector<long long> P = getDp(X[1]);
    sort(X[2].rbegin(), X[2].rend());
    int sz = (int) X[2].size();
    long long ans = 0;
    for (int can = 0, cur = 0, pos = 0; can <= m; can++) {
        while (can > cur && pos < sz) {
            cur += X[2][pos];
            pos++;
        }
        if (can > cur) {
            break;
        }
        if (can + pos > m) {
            break;
        }
        ans = max(ans, P[can] + R[max(0, m - can - pos)]);
    }
    cout << ans << '\n';
 
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int K = 3;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> X(K);
    for (int i = 0; i < n; i++) {
        int t, x;
        cin >> t >> x;
        X[t].emplace_back(x);
    }

    auto getDp = [&](vector<int>& x) -> vector<long long> {
        sort(x.rbegin(), x.rend());
        vector<long long> dp(m + 1, -INF);
        dp[0] = 0;
        int len = (int) x.size();
        for (int i = 0; i < min(len, m); i++) {
            dp[i + 1] = dp[i] + x[i];
        }
        for (int i = len + 1; i <= m; i++) {
            dp[i] = dp[i - 1];
        }
        return dp;
    };

    vector<long long> R = getDp(X[0]);
    vector<long long> P = getDp(X[1]);
    sort(X[2].rbegin(), X[2].rend());
    int sz = (int) X[2].size();
    long long ans = 0;
    for (int can = 0, cur = 0, pos = 0; can <= m; can++) {
        while (can > cur && pos < sz) {
            cur += X[2][pos];
            pos++;
        }
        if (can > cur) {
            break;
        }
        if (can + pos > m) {
            break;
        }
        ans = max(ans, P[can] + R[max(0, m - can - pos)]);
    }
    cout << ans << '\n';

    return 0;
}
Submission Info