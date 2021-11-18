#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

long long dp[N][N];
long long a[N][N];
bool marked[N][N];
bool before[N][N];

long long get(int x1, int y1, int x2, int y2) {
    return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 1; i < N; i++) {
        a[i][1] = 1;
        a[1][i] = 1;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 2; j < N; j++) {
            a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }
    for (int i = 1; i < N; i++) {
        long long pre = 0;
        for (int j = 1; j < N; j++) {
            pre += a[i][j];
            dp[i][j] = dp[i - 1][j] + pre;
        }
    }
    int n, m, q;
    cin >> n >> m >> q;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans += get(1, 1, n - i + 1, m - j + 1);
            marked[i][j] = true;
        }
    }
    vector<pair<int, int>> p(q);
    for (int i = 0; i < q; i++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < q; i++) {
        auto [x, y] = p[i];
        marked[x][y] = !(marked[x][y]);
        long long cur = get(1, 1, n - x + 1, m - y + 1);
        vector<pair<int, int>> bf;
        for (int j = 0; j < i; j++) {
            auto [cx, cy] = p[j];
            if (marked[cx][cy]) {
                continue;
            }
            if (cx <= x || cy <= y) {
                continue;
            }
            if (before[cx][cy]) {
                continue;
            }
            bf.emplace_back(cx, cy);
            before[cx][cy] = true;
        }
        for (auto [cx, cy] : bf) {
            before[cx][cy] = false;
            cur -= get(1, 1, n - cx + 1, m - cy + 1);
        }
        if (marked[x][y]) {
            ans += cur;
        } else {
            ans -= cur;
        }
        cout << ans << '\n';
    }
    
    return 0;
}