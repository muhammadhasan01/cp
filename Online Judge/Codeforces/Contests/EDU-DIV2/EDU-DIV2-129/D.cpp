#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    unsigned long long x;
    cin >> n >> x;
    map<unsigned long long, int> dist;
    priority_queue<pair<unsigned long long, int>> pq;
    dist[x] = 0;
    pq.emplace(x, dist[x]);
    int ans = INF;
    while (!pq.empty()) {
        auto [val, cnt] = pq.top();
        pq.pop();
        if (dist[val] != cnt) {
            continue;
        }
        string s = to_string(val);
        int len = (int) s.length();
        if (len > n) {
            cout << -1 << '\n';
            return;
        }
        if (len == n) {
            ans = min(ans, cnt);
            continue;
        }
        sort(s.rbegin(), s.rend());
        for (char cc : s) {
            int num = cc - '0';
            if (num <= 1) {
                continue;
            }
            unsigned long long cur = val * num;
            if (dist.count(cur) == 0 || dist[cur] > dist[val] + 1) {
                dist[cur] = dist[val] + 1;
                pq.emplace(cur, dist[cur]);
            }
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
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}