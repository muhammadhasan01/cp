#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int dist[N];

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> val(n), c(n);
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        val[i] = dist[b];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int sum = accumulate(val.begin(), val.end(), 0);
    if (sum <= k) {
        cout << accumulate(c.begin(), c.end(), 0) << '\n';
        return;
    }
    vector<int> dp(k + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<int> ndp(k + 1, -1);
        for (int j = 0; j <= k; j++) {
            if (dp[j] != -1) {
                ndp[j] = max(ndp[j], dp[j]);
            }
            if (j - val[i] >= 0 && dp[j - val[i]] != -1) {
                ndp[j] = max(ndp[j], dp[j - val[i]] + c[i]);
            }
        }
        dp.swap(ndp);
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.emplace(1);
    dist[1] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 1; i <= u; i++) {
            int res = u / i;
            int cur = u + res;
            if (cur < N && dist[cur] == -1) {
                dist[cur] = 1 + dist[u];
                q.emplace(cur);
            }
            i = u / res;
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}