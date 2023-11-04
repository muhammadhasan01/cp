#include <bits/stdc++.h>

using namespace std;

const int K = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    map<pair<int, int>, pair<int, int>> ans;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y] = p[i];
        cin >> x >> y;
        ans[{x, y}] = {-1, -1};
    }
    queue<pair<int, int>> q;
    for (auto [x, y] : p) {
        for (int i = 0; i < K; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            if (ans.count({cx, cy})) {
                continue;
            }
            q.emplace(cx, cy);
        }
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        pair<int, int> now = {x, y};
        for (int i = 0; i < K; i++) {
            int cx = x + dx[i];
            int cy = y + dy[i];
            pair<int, int> cur = {cx, cy};
            if (!ans.count(cur)) {
                continue;
            }
            if (ans[cur].first == -1) {
                ans[cur] = (ans.count(now) ? ans[now] : now);
                q.emplace(cx, cy);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        auto [x, y] = ans[p[i]];
        cout << x << " " << y << '\n';
    }
    
    return 0;
}