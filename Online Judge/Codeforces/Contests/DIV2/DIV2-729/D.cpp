#include <bits/stdc++.h>

using namespace std;

const int M = 998244353;

template<typename T>
void add(T& a, T b) {
    a = (a + b) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        char cc;
        cin >> cc;
        if (cc == '-') {
            a[i] = -1;
        } else {
            cin >> a[i];
        }
    }
    vector<vector<int>> dp(2, vector<int>(n + 2));
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            continue;
        }
        fill(dp[0].begin(), dp[0].end(), 0);
        dp[0][0] = 1;
        for (int j = 1; j <= n; j++) {
            int now = (j & 1);
            int bfr = 1 - now;
            fill(dp[now].begin(), dp[now].end(), 0);
            for (int k = 0; k <= n; k++) {
                add(dp[now][k], dp[bfr][k]);
                if (j == i) {
                    continue;
                }
                if (a[j] == -1) {
                    add(dp[now][k], dp[bfr][k + 1]);
                    if (k == 0 && j < i) {
                        add(dp[now][k], dp[bfr][k]);
                    }
                } else if (a[j] > a[i]) {
                    add(dp[now][k], dp[bfr][k]);
                } else {
                    bool less = (a[j] < a[i] || (a[j] == a[i] && j < i));
                    if (less && k == 0) {
                        continue;
                    }
                    add(dp[now][k], dp[bfr][k - less]);
                }
            }
        }
        int bit = (n & 1);
        long long cur = 0;
        for (int k = 0; k <= n; k++) {
            add(cur, (long long) dp[bit][k]);
        }
        cur = (cur * a[i]) % M;
        ans = (ans + cur) % M;
    }
    cout << ans << '\n';

    return 0;
}