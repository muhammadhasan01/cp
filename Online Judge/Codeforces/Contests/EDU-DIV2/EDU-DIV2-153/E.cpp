#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<vector<int>>> pos(K, vector<vector<int>>(K));
    for (int i = 0; i < n - 1; i++) {
        pos[(int) (s[i] - 'a')][(int) (s[i + 1] - 'a')].emplace_back(i);
    }
    vector<vector<vector<int>>> dist(K, vector<vector<int>>(K, vector<int>(n, -1)));
    for (int a = 0; a < K; a++) {
        for (int b = 0; b < K; b++) {
            if (!pos[a][b].empty()) {
                vector<vector<bool>> vis(K, vector<bool>(K));
                queue<int> q;
                vis[a][b] = true;
                for (int i : pos[a][b]) {
                    dist[a][b][i] = 0;
                    q.emplace(i);
                }
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    if (x - 1 >= 0 && dist[a][b][x - 1] == -1) {
                        dist[a][b][x - 1] = dist[a][b][x] + 1;
                        q.emplace(x - 1);
                    }
                    if (x + 1 < n - 1 && dist[a][b][x + 1] == -1) {
                        dist[a][b][x + 1] = dist[a][b][x] + 1;
                        q.emplace(x + 1);
                    }
                    int l = s[x] - 'a', r = s[x + 1] - 'a';
                    if (!vis[l][r]) {
                        vis[l][r] = true;
                        for (auto i : pos[l][r]) {
                            if (dist[a][b][i] == -1) {
                                dist[a][b][i] = dist[a][b][x] + 1;
                                q.emplace(i);
                            }
                        }
                    }
                }
            }
        }
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        int ans = abs(x - y);
        for (int a = 0; a < 26; a++) {
            for (int b = 0; b < 26; b++) {
                if (!pos[a][b].empty()) {
                    ans = min(ans, dist[a][b][x] + dist[a][b][y] + 1);
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
