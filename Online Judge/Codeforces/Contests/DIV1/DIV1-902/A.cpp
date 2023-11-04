#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
    }
    sort(p.begin(), p.end());
    long long ans = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(-INT_MAX, 1);
    for (auto [b, a] : p) {
        auto [minval, tries] = pq.top();
        int val = -minval;
        if (val > x) {
            ans += 1LL * x;
        } else {
            pq.pop();
            ans += 1LL * val;
            if (tries > 1) {
                pq.emplace(minval, tries - 1);
            }
        }
        pq.emplace(-b, a);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}