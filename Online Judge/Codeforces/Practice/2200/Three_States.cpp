#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int K = 3;
const int INF = 1e7;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char a[N][N];
bool vis[N][N];
int dist[N][N][K + 1];
int nearest[K + 1][K + 1];

void dismiss() {
    cout << -1 << '\n';
    exit(0);
}

void getDist(int ord) {
    char CC = char(int('1') + ord - 1);
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j][ord] = INF;
            if (a[i][j] != CC) continue;
            dist[i][j][ord] = 0;
            q.emplace(i, j);
        }
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int curdist = dist[cur.first][cur.second][ord];
        for (int i = 0; i < 4; i++) {
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if (x < 1 || x > n) continue;
            if (y < 1 || y > m) continue;
            if (a[x][y] == '#') continue;
            if (a[x][y] == CC) continue;
            if (dist[x][y][ord] > curdist + 1) {
                dist[x][y][ord] = curdist + 1;
                q.emplace(x, y);
            }
        }
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int it = 1; it <= K; it++) {
        getDist(it);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3') {
                if (dist[i][j][1] == INF) dismiss();
            }
        }
    }
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= K; j++) {
            nearest[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == '1' || a[i][j] == '2' || a[i][j] == '3') {
                int ord = a[i][j] - '0';
                for (int it = 1; it <= K; it++) {
                    nearest[it][ord] = min(nearest[it][ord], dist[i][j][it] - 1);
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != '.') continue;
            int cur = 1;
            for (int it = 1; it <= K; it++) {
                cur += (dist[i][j][it] - 1);
            }
            ans = min(ans, cur);
        }
    }
    vector<int> v = {1, 2, 3};
    do {
        int cur = 0;
        for (int i = 0; i < K - 1; i++) {
            cur += nearest[v[i]][v[i + 1]];
        }
        ans = min(ans, cur);
    } while (next_permutation(v.begin(), v.end()));
    assert(ans != INF);
    cout << ans << '\n';

    return 0;
}