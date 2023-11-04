#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<vector<long long>> g(2, vector<long long>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<long long>> pre(2, vector<long long>(n));
    vector<vector<long long>> inc(2, vector<long long>(n));
    vector<vector<long long>> dec(2, vector<long long>(n));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            pre[i][j] = (j > 0 ? pre[i][j - 1] : 0LL) + g[i][j];
            inc[i][j] = (j > 0 ? inc[i][j - 1] : 0LL) + g[i][j] * j;
        }
        for (int j = n - 1, k = 0; j >= 0; j--, k++) {
            dec[i][j] = (j + 1 < n ? dec[i][j + 1] : 0LL) + g[i][j] * k;
        }
    }

    long long sum = 0;

    auto getRange = [&](vector<long long>& v, int l, int r, bool fromLeft) -> long long {
        if (l > r) {
            return 0LL;
        }
        if (fromLeft) {
            return v[r] - (l > 0 ? v[l - 1] : 0);
        }
        return v[l] - (r + 1 < n ? v[r + 1] : 0);
    };

    auto getUpper = [&](int y, int k) -> long long {
        long long rgt = getRange(inc[0], y, n - 1, 1) + getRange(pre[0], y, n - 1, 1) * (k - y);
        long long lft = 0;
        if (k % 4 == 0) {
            lft = getRange(dec[1], y, n - 1, 0) + getRange(pre[1], y, n - 1, 1) * (n - y + k);
        } else if (k % 4 == 3) {
            lft = getRange(dec[1], y + 1, n - 1, 0) + getRange(pre[1], y + 1, n - 1, 1) * (n - y + k);
        }
        return sum + rgt + lft;
    };

    auto getLower = [&](int y, int k) -> long long {
        long long rgt = getRange(inc[1], y, n - 1, 1) + getRange(pre[1], y, n - 1, 1) * (k - y);
        long long lft = 0;
        if (k % 4 == 1) {
            lft = getRange(dec[0], y + 1, n - 1, 0) + getRange(pre[0], y + 1, n - 1, 1) * (n - y + k);
        } else if (k % 4 == 2) {
            lft = getRange(dec[0], y, n - 1, 0) + getRange(pre[0], y, n - 1, 1) * (n - y + k);
        }
        return sum + rgt + lft;
    };

    vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, 1}};
    int dirSize = dir.size();
    long long ans = 0;
    for (int it = 0, x = 0, y = 0; ; it++) {
        if (x % 2 == 0) {
            ans = max(ans, getUpper(y, it));
        } else {
            ans = max(ans, getLower(y, it));
        }
        sum += g[x][y] * it;
        if (x == 1 && y == n - 1) {
            break;
        }
        x += dir[it % dirSize].first;
        y += dir[it % dirSize].second;
    }
    cout << max(ans, sum) << '\n';
    
    return 0;
}