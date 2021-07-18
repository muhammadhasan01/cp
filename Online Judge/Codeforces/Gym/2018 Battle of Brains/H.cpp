#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

void solve() {
    string str;
    cin >> str;
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n));
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n; i++) {
            int j = i + len - 1;
            if (j >= n) {
                break;
            }
            dp[i][j] = dp[i + 1][j - 1] + abs(str[i] - str[j]);
        }
    }

    auto can = [&](int l, int r, int mxt, int sub) -> bool {
        if (l + sub >= r - sub) {
            return true;
        }
        int tol = dp[l + sub][r - sub];
        return tol <= mxt;
    };

    int q;
    cin >> q;
    while (q--) {
        int x, y, mxt;
        cin >> x >> y >> mxt;
        x--, y--;
        int l = 0, r = INF, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (can(x, y, mxt, mid)) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        int len = y - x + 1;
        cout << len - 2 * at << '\n';
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}