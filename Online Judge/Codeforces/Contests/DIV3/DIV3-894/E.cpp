#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    long long d;
    cin >> n >> m >> d;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int sz = m - 1;
    long long ans = 0;
    long long maxsum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 1; i <= n; i++) {
        long long cur = a[i] - d * i + maxsum;
        ans = max(ans, cur);
        if (a[i] > 0) {
            int len = (int) pq.size();
            if (len < sz) {
                pq.emplace(a[i]);
                maxsum += a[i];
            } else if (len == sz) {
                pq.emplace(a[i]);
                maxsum += a[i] - pq.top();
                pq.pop();
            }
        }
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