#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    int len = 0;
    int su = -1, sv = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'x') {
                ++len;
                if (su == -1 && sv == -1) {
                    su = i;
                    sv = j;
                }
            }
        }
    }
    vector<vector<int>> num(n + 1, vector<int>(n + 1));
    queue<pair<int, int>> q;
    vector<pair<int, int>> loc(len + 1);
    q.emplace(su, sv);
    num[su][sv] = 1;
    while (!q.empty()) {
        auto [u, v] = q.front();
        loc[num[u][v]] = make_pair(u, v);
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nu = u + dx[i];
            int nv = v + dy[i];
            if (nu < 1 || nu > n || nv < 1 || nv > n) {
                continue;
            }
            if (a[nu][nv] != 'x') {
                continue;
            }
            if (num[nu][nv] == 0) {
                num[nu][nv] = 1 + num[u][v];
                q.emplace(nu, nv);
                break;
            }
        }
    }
    auto get_distance = [&](int i, int j) -> int {
        if (j > len) {
            j -= len;
        }
        auto [u, v] = loc[i];
        auto [nu, nv] = loc[j];
        return abs(u - nu) + abs(v - nv);
    };
    vector<int> dist(len + 1, INF);
    for (int d = 1; d <= len; d++) {
        for (int i = 1; i <= len; i++) {
            int cur = get_distance(i, i + d);
            dist[d] = min(dist[d], cur);    
        }
    }
    vector<vector<int>> dp(k + 1, vector<int>(len + 1, -1));
    dp[0][0] = INF;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= len; j++) {
            int now = dp[i - 1][j];
            if (now == -1) {
                continue;
            }
            for (int d = 1; d <= len; d++) {
                if (j + d > len) {
                    break;
                }
                int cur = min(now, dist[d]);
                dp[i][j + d] = max(dp[i][j + d], cur);
            }
        }
    }
    cout << dp[k][len] << '\n';

    return 0;
}