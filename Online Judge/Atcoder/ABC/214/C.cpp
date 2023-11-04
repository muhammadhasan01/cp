#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>> pq;
    for (int i = 0; i < n; i++) {
        dist[i] = t[i];
        pq.emplace(-dist[i], i);
    }
    while (!pq.empty()) {
        auto [d, i] = pq.top();
        pq.pop();
        if (dist[i] != -d) {
            continue;
        }
        int j = (i + 1) % n;
        if (dist[j] > dist[i] + s[i]) {
            dist[j] = dist[i] + s[i];
            pq.emplace(-dist[j], j);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << dist[i] << '\n';
    }
    
    return 0;
}