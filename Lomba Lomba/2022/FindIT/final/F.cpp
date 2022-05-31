#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }
    long long ans = LLONG_MAX;
    for (int it = 0; it <= n - 1; it++) {
        long long sum = pre[n - it] + a[0] * it;
        long long cur = it;
        if (sum > k) {
            long long dif = sum - k;
            cur += (dif + it) / (it + 1); 
        }
        ans = min(ans, cur);
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
        solve();
    }
    
    return 0;
}