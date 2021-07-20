#include <bits/stdc++.h>

using namespace std;

const int dx[] = {1, -1};
const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    vector<int> portals;
    int st = -1, ed = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 's' || s[i] == 'e') {
            if (s[i] == 's') {
                st = i;
            } else if (s[i] == 'e') {
                ed = i;
            }
            for (int j = i + 1; j < n; j++) {
                if (s[j] == '.') {
                    pos.emplace_back(j);
                    break;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                if (s[j] == '.') {
                    pos.emplace_back(j);
                    break;
                }
            }
        } else if (s[i] == 'o') {
            portals.emplace_back(i);
        }
    }
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());
    int len = pos.size();
    int ans = INF;
    for (int mask = 0; mask < (1 << len); mask++) {
        vector<int> bits;
        for (int i = 0; i < len; i++) {
            bool b = mask & (1 << i);
            if (b) {
                bits.emplace_back(i);
                s[pos[i]] = '#';
            }
        }
        vector<bool> vis(n);
        queue<int> q;
        q.emplace(st);
        vis[st] = 1;
        bool portal = false;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (s[u] == 'o' && !portal) {
                portal = true;
                for (int x : portals) {
                    if (!vis[x]) {
                        vis[x] = true;
                        q.emplace(x);
                    }
                }
            }
            for (int i = 0; i < 2; i++) {
                int v = u + dx[i];
                if (v < 0 || v >= n) {
                    continue;
                }
                if (s[v] == '#') {
                    continue;
                }
                if (vis[v] == 1) {
                    continue;
                }
                vis[v] = 1;
                q.emplace(v);
            }
        }
        if (vis[ed] == 0) {
            ans = min(ans, (int) bits.size());
        }
        for (int i : bits) {
            s[pos[i]] = '.';
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

    freopen("portals.in", "r", stdin);
    
    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}