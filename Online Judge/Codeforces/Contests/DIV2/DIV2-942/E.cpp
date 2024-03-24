#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int K = 750;

int F[K];
int dp[N];
int minlen[N];

void solve() {
    int n;
    long long x, y, s;
    cin >> n >> x >> y >> s;
    long long rem = x % y;
    s -= rem * n;
    if (s < 0 || s % y != 0) {
        cout << "NO" << '\n';
        return;
    }
    s /= y;
    x = (x - rem) / y;
    long long sum = x;
    vector<int> operations;

    auto check = [&](int i) -> bool {
        int len = n - i + 1;
        long long cur = s - sum;
        if (cur < 0) {
            return false;
        }
        if (minlen[cur] == -1 || minlen[cur] > len) {
            return false;
        }
        vector<int>().swap(operations);
        while (len > 0 && cur > 0) {
            operations.emplace_back(dp[cur]);
            cur -= F[dp[cur]];
            len -= dp[cur];
        }
        return cur == 0;
    };

    for (int i = 2; i <= n; i++) {
        if (check(i)) {
            x = x * y + rem;
            vector<int> values(n + 1);
            values[1] = x;
            int j = 2;
            while (j < i) {
                values[j] = values[j - 1] + y;
                ++j;
            }
            for (int op : operations) {
                values[j] = values[j - 1] % y;
                ++j;
                for (int k = 1; k < op; k++) {
                    values[j] = values[j - 1] + y;
                    ++j;
                }
            }
            while (j <= n) {
                values[j] = values[j - 1] % y;
                j++;
            }
            cout << "YES" << '\n';
            for (int k = 1; k <= n; k++) {
                cout << values[k] << " \n"[k == n];
            }
            return;
        }
        sum += (x + i - 1);
    }
    if (sum != s) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    x = x * y + rem;
    for (int i = 1; i <= n; i++) {
        cout << x << " \n"[i == n];
        x = x + y;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 1; i < K; i++) {
        F[i] = i * (i - 1) / 2;
    }
    memset(dp, -1, sizeof(dp));
    memset(minlen, -1, sizeof(minlen));
    dp[0] = 0;
    minlen[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < K; j++) {
            int cur = i - F[j];
            if (cur < 0) {
                break;
            }
            if (dp[cur] == -1) {
                continue;
            }
            if (minlen[i] == -1 || minlen[i] > j + minlen[cur]) {
                minlen[i] = j + minlen[cur];
                dp[i] = j;
            }
        }
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}