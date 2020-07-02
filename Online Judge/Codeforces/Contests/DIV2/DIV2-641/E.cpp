#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const long long INF = 1e18 + 500;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, tc;
char a[N][N];
long long min_time[N][N];

char change(char CC) {
    if (CC == '1') return '0';
    if (CC == '0') return '1';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> tc;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            min_time[i][j] = INF;
        }
    }
    deque<pair<int, int>> dq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 0; k < 4; k++) {
                int ri = i + dx[k];
                int ry = j + dy[k];
                if (a[i][j] == a[ri][ry] && min_time[ri][ry] == INF) {
                    min_time[ri][ry] = 0;
                    dq.push_front({ri, ry});
                }
            }
        }
    }
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int rx = x + dx[i];
            int ry = y + dy[i];
            if (rx < 1 || rx > n) continue;
            if (ry < 1 || ry > m) continue;
            if (a[x][y] == a[rx][ry] && min_time[x][y] < min_time[rx][ry]) {
                min_time[rx][ry] = min_time[x][y];
                dq.push_front({rx, ry});
            } else if (a[x][y] != a[rx][ry] && min_time[x][y] + 1 < min_time[rx][ry]) {
                min_time[rx][ry] = 1 + min_time[x][y];
                dq.push_back({rx, ry});
            }
        }
    }
    while (tc--) {
        int x, y;
        long long p;
        cin >> x >> y >> p;
        long long dif = max(0LL, p - min_time[x][y]);
        cout << (dif & 1 ? change(a[x][y]) : a[x][y]) << '\n';
    }

    return 0;
}