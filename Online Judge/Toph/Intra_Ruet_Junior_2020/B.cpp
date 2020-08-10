// WA
#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 1e4 + 5;

struct st {
    int x, y, z;
};

int tc;
int n, m;
pair<int, int> p[N];
bool dp[M][N][2], pd[M][N][2];
st go[M][N][2], og[M][N][2];

void init() {
    for (int val = 0; val <= m; val++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++)
                dp[val][i][j] = 0;
        }
    }
    for (int val = 0; val <= m; val++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 2; j++)
                pd[val][i][j] = 0;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    init();
    if (m == 0) {
        cout << "NO" << '\n';
        return;
    }
    dp[0][0][0] = dp[0][0][1] = 1;
    for (int val = 1; val <= m; val++) {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                if (p[i].first <= val && dp[val - p[i].first][i - 1][j] == 1) {
                    dp[val][i][0] = 1;
                    go[val][i][0] = {val - p[i].first, i - 1, j};
                }
                if (p[i].second <= val && dp[val - p[i].second][i - 1][j] == 1) {
                    dp[val][i][1] = 1;
                    go[val][i][1] = {val - p[i].second, i - 1, j};
                }
            }
        }
    }
    pd[0][n + 1][0] = pd[0][n + 1][1] = 1;
    for (int val = 1; val <= m; val++) {
        for (int i = n; i > 1; i--) {
            for (int j = 0; j < 2; j++) {
                if (p[i].first <= val && pd[val - p[i].first][i + 1][j] == 1) {
                    pd[val][i][0] = 1;
                    og[val][i][0] = {val - p[i].first, i + 1, j};
                }
                if (p[i].second <= val && pd[val - p[i].second][i + 1][j] == 1) {
                    pd[val][i][1] = 1;
                    og[val][i][1] = {val - p[i].second, i + 1, j};
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 2; k++) {
                for (int l = 0; l < 2; l++) {
                    if (dp[j][i - 1][k] == 0 || pd[m - j][i + 1][l] == 0) continue;
                    cout << "YES" << '\n';
                    // First Part
                    deque<int> ans;
                    int x = j, y = i - 1, z = k;
                    while (y > 0) {
                        ans.emplace_front(z + 1);
                        auto cur = go[x][y][z];
                        x = cur.x, y = cur.y, z = cur.z;
                    }
                    // Zero part
                    ans.emplace_back(0);
                    // Second Part
                    x = m - j, y = i + 1, z = l;
                    queue<int> q;
                    while (y <= n) {
                        q.emplace(z + 1);
                        auto cur = og[x][y][z];
                        x = cur.x, y = cur.y, z = cur.z;
                    }
                    while (!q.empty()) {
                        ans.emplace_back(q.front());
                        q.pop();
                    }
                    for (int i = 0; i < n; i++) {
                        cout << ans[i] << (i == n - 1 ? '\n' : ' ');
                    }
                    return;
                }
            }
        }
    }
    cout << "NO" << "\n";
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}