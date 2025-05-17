#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> d(n, 1);
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.emplace(-a[i] * (2 * d[i] + 1), i);
    }
    for (int i = 0; i < n - 2; i++) {
        auto [_, j] = pq.top();
        pq.pop();
        d[j]++;
        pq.emplace(-a[j] * (2 * d[j] + 1), j);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i] * d[i] * a[i];
    }
    cout << ans << '\n';
    
    return 0;
}