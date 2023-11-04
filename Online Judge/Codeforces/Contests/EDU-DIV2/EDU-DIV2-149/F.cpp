#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto can = [&](long long x) -> bool {
        vector<int> L(n + 1);
        {
            priority_queue<int> pq;
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                pq.emplace(a[i]);
                sum += a[i];
                if (sum > x) {
                    sum -= pq.top();
                    pq.pop();
                }
                L[i + 1] = (int) pq.size();
            }
        }
        vector<int> R(n + 1);
        {
            priority_queue<int> pq;
            long long sum = 0;
            for (int i = n - 1; i >= 0; i--) {
                pq.emplace(a[i]);
                sum += a[i];
                if (sum > x) {
                    sum -= pq.top();
                    pq.pop();
                }
                R[i] = (int) pq.size();
            }
        }
        for (int i = 0; i <= n; i++) {
            if (L[i] + R[i] >= k) {
                return true;
            }
        }
        return false;
    };

    long long l = 1, r = INF, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
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