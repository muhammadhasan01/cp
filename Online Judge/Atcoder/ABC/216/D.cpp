#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> pos(n + 1);
    vector<vector<int>> cylinder(m);
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        cylinder[i].resize(k);
        for (auto& j : cylinder[i]) {
            cin >> j;
            pos[j].emplace_back(i);
        }
    }
    vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        cnt[cylinder[i].back()]++;
    }
    vector<bool> vis(n + 1);
    queue<int> q;
    for (int x = 1; x <= n; x++) {
        if (cnt[x] == 2) {
            q.emplace(x);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = true;
        for (int i : pos[x]) {
            cylinder[i].pop_back();
            if (!cylinder[i].empty()) {
                int y = cylinder[i].back();
                if (++cnt[y] == 2) {
                    q.emplace(y);
                }
            }
        }
    }
    for (int x = 1; x <= n; x++) {
        if (!vis[x]) {
            cout << "No" << '\n';
            return 0;
        }
    }
    cout << "Yes" << "\n";
    
    return 0;
}