#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

int tc;
int n, m;
char a[N][N];
bool vis[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
                if (a[i][j] == 'G') ++cnt;
            }
        }
        if (cnt == 0) {
            cout << "Yes" << '\n';
            continue;
        }
        a[n][m] = 'G';
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 'B') {
                    for (int it = 0; it < 4; it++) {
                        int ci = i + dx[it];
                        int cj = j + dy[it];
                        if (ci < 1 || ci > n) continue;
                        if (cj < 1 || cj > m) continue;
                        if (a[ci][cj] == 'G') {
                            flag = false;
                            break;
                        } else if (a[ci][cj] == '.') {
                            a[ci][cj] = '#';
                        }
                    }
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (!flag) {
            cout << "No" << "\n";
            continue;
        }
        queue<pair<int, int>> q;
        q.emplace(n, m);
        vis[n][m] = 1;
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int it = 0; it < 4; it++) {
                int ci = i + dx[it];
                int cj = j + dy[it];
                if (ci < 1 || ci > n) continue;
                if (cj < 1 || cj > m) continue;
                if (a[ci][cj] == 'B' || a[ci][cj] == '#') continue;
                if (vis[ci][cj]) continue;
                vis[ci][cj] = 1;
                q.emplace(ci, cj);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 'G') {
                    if (vis[i][j] == 0) {
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag) break;
        }
        cout << (flag ? "Yes" : "No") << '\n';
    }

    return 0;
}