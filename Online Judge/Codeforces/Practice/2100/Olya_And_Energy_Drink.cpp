#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m, k;
bitset<N> a[N];
int dp[N][N];
int x_1, y_1, x_2, y_2;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            a[i][j] = (x == '#');
            dp[i][j] = -1;
        }
    }
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    queue<pair<int, int>> q;
    q.push({x_1, y_1});
    dp[x_1][y_1] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int cur_x = x + dx[i];
            int cur_y = y + dy[i];
            int cnt = 0;
            while (cnt < k && a[cur_x][cur_y] == 0 && (dp[cur_x][cur_y] == -1 || 
                   dp[cur_x][cur_y] > dp[x][y])) {
                if (dp[cur_x][cur_y] == -1) {
                    dp[cur_x][cur_y] = 1 + dp[x][y];
                    q.push({cur_x, cur_y});
                }
                cur_x += dx[i];
                cur_y += dy[i];
                cnt++;
            }
        }
    }
    cout << dp[x_2][y_2] << '\n';

    return 0;
}