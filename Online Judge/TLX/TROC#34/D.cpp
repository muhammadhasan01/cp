#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    int k;
    cin >> k;
    vector<long long> A(k);
    vector<int> freq(n + 1);
    for (int i = 0; i < k; i++) {
        int b;
        cin >> A[i] >> b;
        freq[b]++;
    }
    sort(A.begin(), A.end());
    long long sumA = LLONG_MAX;
    {
        long long sum = accumulate(A.begin(), A.end(), 0LL);
        long long pre = 0;
        for (int i = 0; i < k; i++) {
            pre += A[i];
            long long L = 1LL * (i + 1) * A[i] - pre;
            long long R = (sum - pre) - 1LL * (k - i - 1) * A[i];
            sumA = min(sumA, L + R);
        }
    }

    vector<long long> dp(n + 1);
    vector<long long> cnt(n + 1);

    function<void(int, int)> dfs = [&](int u, int p) {
        cnt[u] += freq[u];
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            dp[u] += dp[v] + cnt[v];
            cnt[u] += cnt[v];
        }
    };

    dfs(1, 1);
    long long sumB = dp[1];
    vector<long long> tempDp(n + 1);
    vector<long long> tempCnt(n + 1);

    function<void(int, int)> reroot = [&](int u, int p) {
        if (u != p) {
            dp[u] += dp[p] + cnt[p];
            cnt[u] += cnt[p];
            sumB = min(sumB, dp[u]);
        }
        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }
            tempDp[u] = dp[u];
            tempCnt[u] = cnt[u];
            dp[u] -= dp[v] + cnt[v];
            cnt[u] -= cnt[v];
            reroot(v, u);
            dp[u] = tempDp[u];
            cnt[u] = tempCnt[u];
        }
    };

    reroot(1, 1);

    cout << sumA + sumB << '\n';
    
    return 0;
}