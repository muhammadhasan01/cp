#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

const int INF = 2e9;
const pii DEFAULT = {INF, -1};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string useless;
    cin >> useless;
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<vector<char>> grid(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    auto getId = [&](int i, int j) -> int {
        return (i - 1) * m + j;
    };

    auto getRowCol = [&](int id) -> pii {
        int row = (id - 1) / m + 1;
        int col = id - (row - 1) * m;
        return {row, col};
    };

    vector<vector<pii>> dp(n + 2, vector<pii>(m + 2, DEFAULT));
    vector<vector<pii>> res(n + 2, vector<pii>(m + 2, DEFAULT));

    auto resetDp = [&]() -> void {
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                dp[i][j] = DEFAULT;
            }
        }
    };

    auto merge = [&](pii L, pii R) -> pii {
        if (L.first != R.first) {
            return min(L, R);
        }
        if (L.second != R.second) {
            return {L.first, -1};
        }
        return L;
    };

    // Q1
    resetDp();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                dp[i][j] = {0, getId(i, j)};
            } else {
                dp[i][j] = merge(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j].first++;
            }
            res[i][j] = merge(res[i][j], dp[i - 1][j]);
        }
    }
    // Q2
    resetDp();
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            if (grid[i][j] == 'X') {
                dp[i][j] = {0, getId(i, j)};
            } else {
                dp[i][j] = merge(dp[i - 1][j], dp[i][j + 1]);
                dp[i][j].first++;
            }
            res[i][j] = merge(res[i][j], dp[i][j + 1]);
        }
    }
    // Q3
    resetDp();
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                dp[i][j] = {0, getId(i, j)};
            } else {
                dp[i][j] = merge(dp[i + 1][j], dp[i][j - 1]);
                dp[i][j].first++;
            }
            res[i][j] = merge(res[i][j], dp[i][j - 1]);
        } 
    }
    // Q4
    resetDp();
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            if (grid[i][j] == 'X') {
                dp[i][j] = {0, getId(i, j)};
            } else {
                dp[i][j] = merge(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j].first++;
            }
            res[i][j] = merge(res[i][j], dp[i + 1][j]);
        }
    }
    vector<int> par(n * m + 1, -1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j] == 'X') {
                par[getId(i, j)] = res[i][j].second;
            }
        }
    }
    vector<int> memo(n * m + 1, -1);

    function<int(int)> getFinalId = [&](int id) {
        if (par[id] == -1) {
            return id;
        }
        if (memo[id] != -1) {
            return memo[id];
        }
        if (id == par[par[id]]) {
            return memo[id] = par[id];
        }
        return memo[id] = getFinalId(par[id]);
    };

    auto answerQuery = [&](int x, int y) -> void {
        if (res[x][y].second == -1) {
            cout << x << ' ' << y << '\n';
            return;
        }
        int id = getFinalId(res[x][y].second);
        auto [r, c] = getRowCol(id);
        cout << r << ' ' << c << '\n';
    };

    while (q--) {
        int x, y;
        cin >> x >> y;
        answerQuery(x, y);
    }

    return 0;
}