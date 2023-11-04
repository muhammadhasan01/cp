#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int N = 5E3 + 5;

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> r(n, vector<int>(m + 1));
    for (int i = 0; i < n; i++) {
        cin >> r[i][m];
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cin >> r[i][j];
        }
    }
    sort(r.begin(), r.end());
    vector<bitset<N>> lower(n);
    for (int i = 0; i < n; i++) {
        lower[i].set();
    }
    vector<int> id(n);
    iota(id.begin(), id.end(), 0);
    for (int i = 0; i < m; i++) {
        sort(id.begin(), id.end(), [&](int& lhs, int& rhs) {
            return r[lhs][i] < r[rhs][i];
        });
        bitset<N> cur = 0;
        for (int x = 0, y = 0; y < n; y++) {
            while (r[id[x]][i] < r[id[y]][i]) {
                cur.set(id[x], 1);
                x++;
            }
            lower[id[y]] &= cur;
        }
    }
    vector<long long> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i] = r[i][m];
        for (int j = i - 1; j >= 0; j--) {
            if (lower[i][j]) {
                dp[i] = max(dp[i], dp[j] + r[i][m]);
            }
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}