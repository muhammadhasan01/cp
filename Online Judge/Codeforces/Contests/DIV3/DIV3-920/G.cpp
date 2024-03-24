#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    k += 1;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cc;
            cin >> cc;
            a[i][j] = (cc == '#');
        }
    }

    auto mirrorX = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[i][m - j - 1];
            }
        }
        return ret;
    };

    auto mirrorY = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[n - i - 1][j];
            }
        }
        return ret;
    };

    auto mirrorXY = [&]() -> vector<vector<int>> {
        vector<vector<int>> ret(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = a[n - i - 1][m - j - 1];
            }
        }
        return ret;
    };
    
    auto getMax = [&](vector<vector<int>> s) {
        int N = (int) s.size();
        int M = (int) s[0].size();
        vector<vector<int>> dg(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dg[i][j] = s[i][j];
                if (i - 1 >= 0 && j + 1 < M) {
                    dg[i][j] += dg[i - 1][j + 1];
                }
            }
        }
        vector<vector<int>> pre(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                pre[i][j] = s[i][j];
                if (i - 1 >= 0) {
                    pre[i][j] += pre[i - 1][j];
                }
            }
        }
        vector<vector<int>> sum(N, vector<int>(M));
        int ret = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (j - 1 >= 0) {
                    sum[i][j] += sum[i][j - 1];
                }
                sum[i][j] += pre[i][j];
                if (i - k >= 0) {
                    sum[i][j] -= pre[i - k][j];
                }
                if (j < k) {
                    int ci = j - k + i;
                    if (ci >= 0) {
                        sum[i][j] -= dg[ci][0];
                    }
                } else {
                    sum[i][j] -= dg[i][j - k];
                }
                if (i - k >= 0) {
                    sum[i][j] += dg[i - k][j];
                }
                ret = max(ret, sum[i][j]);
            }
        }
        return ret;
    };

    int ans = getMax(a);
    ans = max(ans, getMax(mirrorX()));
    ans = max(ans, getMax(mirrorY()));
    ans = max(ans, getMax(mirrorXY()));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }

    return 0;
}