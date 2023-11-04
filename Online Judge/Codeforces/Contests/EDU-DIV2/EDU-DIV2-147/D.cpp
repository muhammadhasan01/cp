#include <bits/stdc++.h>

using namespace std;

const int INF = 2E9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> L(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i];
    }
    vector<int> R(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i];
    }
    int sum = 0;
    int ans = INF;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int val = R[i] - L[i] + 1;
        sum += val;
        pq.emplace(val);
        while (sum >= k) {
            int rgt = k - ((sum - val) - L[i] + 1);
            ans = min(ans, 2 * (int) pq.size() + rgt);
            sum -= pq.top();
            pq.pop();
        }
    }
    if (ans == INF) {
        ans = -1;
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