#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long k, d;
    cin >> n >> k >> d;
    vector<long long> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < k; i++) {
        pq.emplace(t[i]);
    }
    for (int i = k; i < n; i++) {
        int mn = pq.top();
        pq.pop();
        int val = max(mn + d, t[i]);
        pq.emplace(val);
    }
    long long ans = 0;
    while (!pq.empty()) {
        ans = max(ans, pq.top() + d);
        pq.pop();
    }
    cout << ans << '\n';
    
    return 0;
}