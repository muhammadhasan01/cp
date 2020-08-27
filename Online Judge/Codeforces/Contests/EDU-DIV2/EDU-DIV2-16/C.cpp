#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int ans[N][N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k = (n + 1) / 2;
    int odd = 1, even = 2;
    for (int i = 1; i <= n; i++) {
        if (odd > n * n) break;
        ans[i][k] = odd;
        odd += 2;
    }
    for (int j = 1; j <= n; j++) {
        if (ans[k][j] > 0) continue;
        if (odd > n * n) break;
        ans[k][j] = odd;
        odd += 2;
    }
    for (int i = 1; i <= k; i++) {
        if (odd > n * n) break;
        for (int j = 1; j <= k; j++) {
            if (ans[i][j]) continue;
            if (odd > n * n) break;
            int ni = n - i + 1, nj = n - j + 1;
            ans[i][j] = odd; odd += 2;
            ans[i][nj] = odd; odd += 2;
            ans[ni][j] = odd; odd += 2;
            ans[ni][nj] = odd; odd += 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] > 0) continue;
            if (even >= n * n) break;
            ans[i][j] = even;
            even += 2;
        }
    }
    int noice = 0, ecoin = 0;
    for (int i = 1; i <= n; i++) {
        noice ^= (ans[i][i] & 1);
        ecoin ^= (ans[n - i + 1][n - i + 1] & 1);
        int res = 0, ser = 0;
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] > n * n || ans[i][j] <= 0) {
                cerr << i << " and " << j << " => " << ans[i][j] << '\n';
            }
            assert(1 <= ans[i][j] && ans[i][j] <= n * n);
            res ^= (ans[i][j] & 1);
            ser ^= (ans[j][i] & 1);
        }
        assert(res == 1);
        assert(ser == 1);
    }
    assert(noice == 1);
    assert(ecoin == 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << (j == n ? '\n' : ' ');
        }
    }

    return 0;
}