#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, m, X, Y, d;
    cin >> n >> m >> X >> Y >> d;
    int k;
    cin >> k;
    vector<pair<long long, long long>> p(k);
    for (int i = 0; i < k; i++) {
        long long x, y, h;
        cin >> x >> y >> h;
        long long dx = abs(X - x);
        long long dy = abs(Y - y);
        long long dist = max(dx, dy);
        long long t = (h + d - 1) / d;
        p[i] = {dist, t};
    }
    sort(p.begin(), p.end());
    int ans = 0;
    long long sumt = 0;
    priority_queue<long long> pq;
    for (auto [dist, t] : p) {
        sumt += t;
        pq.emplace(t);
        if (sumt <= dist) {
            continue;
        }
        while (!pq.empty()) {
            sumt -= pq.top();
            pq.pop();
            sumt += 1;
            ++ans;
            if (sumt <= dist) {
                break;
            }
        }
        if (sumt > dist) {
            cout << -1 << '\n';
            return;
        }
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