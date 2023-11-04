#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        long long val;
        cin >> val;
        pre[i] = pre[i - 1] + val;
    }
    vector<long long> sums(n + 1, -INF);
    sums[0] = 0;
    for (int len = 1; len <= n; len++) {
        for (int i = len; i <= n; i++) {
            long long cur = pre[i] - pre[i - len];
            sums[len] = max(sums[len], cur);
        }
    }
    vector<long long> suff(n + 2, -INF);
    for (int len = n; len >= 0; len--) {
        suff[len] = max(suff[len + 1], sums[len]);
    }
    long long ans = 0;
    for (int k = 0; k <= n; k++) {
        ans = max(ans, suff[k] + x * k);
        cout << ans << " \n"[k == n];
    }
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