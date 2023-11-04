#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string useless;
    cin >> useless;
    int n, sd, sm;
    cin >> n >> sd >> sm;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<tuple<int, int, int>> guards(n - 1);
    for (auto& [p, k, l] : guards) {
        cin >> p >> k >> l;
    }
    long long ans = 0;
    for (auto [p, k, l] : guards) {
        while (p > sd && !pq.empty()) {
            int cur = pq.top();
            pq.pop();
            ans += cur;
            sd++;
        }
        if (p > sd) {
            cout << -1 << '\n';
            return 0;
        }
        if (l <= k) {
            ans += l;
            sd++;
        } else {
            ans += k;
            pq.emplace(l - k);
        }
    }
    while (sm > sd && !pq.empty()) {
        int cur = pq.top();
        pq.pop();
        ans += cur;
        sd++;
    }
    if (sm > sd) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans << '\n';
    
    return 0;
}