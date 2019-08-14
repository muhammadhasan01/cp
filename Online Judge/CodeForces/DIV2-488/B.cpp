#include<bits/stdc++.h>
using namespace std;

struct st{
    long long p, c;
    int idx;
};

const int N = 1e5 + 5;
int n, k;
st a[N];
long long dp[N][15], ans[N];

bool cmpr(st a, st b) {
    return a.p < b.p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].p;
        a[i].idx = i;
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i].c;
    }

    sort(a + 1, a + 1 + n, cmpr);

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            dp[i][1] = a[i].c;
            ans[a[i].idx] = dp[i][1];
        } else if (i <= k) {
            ans[a[i].idx] = a[i].c + dp[i - 1][i - 1];
            for (int j = 1; j <= i; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], a[i].c);
                } else {
                    dp[i][j] = max(dp[i][j], a[i].c + dp[i - 1][j - 1]);
                }
            }
        } else {
            ans[a[i].idx] = a[i].c + dp[i - 1][k];
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j == 1) {
                    dp[i][j] = max(dp[i][j], a[i].c);
                } else {
                    dp[i][j] = max(dp[i][j], a[i].c + dp[i - 1][j - 1]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}
