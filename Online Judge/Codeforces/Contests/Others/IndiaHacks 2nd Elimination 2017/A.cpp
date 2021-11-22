#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;
const int N = 2505;

bool not_prime[N];
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    not_prime[1] = true;
    for (int i = 2; i < N; i++) {
        if (not_prime[i]) {
            continue;
        }
        primes.emplace_back(i);
        for (int j = i + i; j < N; j += i) {
            not_prime[j] = true;
        }
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(2 * n + 5, vector<int>(2 * m + 5));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cc;
            cin >> cc;
            a[i][j] = cc - '0';
        }
    }
    vector<vector<int>> dp(2 * n + 5, vector<int>(2 * m + 5));
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1, pre = 0; j <= 2 * m; j++) {
            pre += a[i][j];
            dp[i][j] = dp[i - 1][j] + pre;
        }
    }
    auto get_area = [&](int x1, int y1, int x2, int y2) {
        return dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
    };
    int ans = INF;
    for (int p : primes) {
        int x = max(p, n + (n % p == 0 ? 0 : p - n % p));
        int y = max(p, m + (m % p == 0 ? 0 : p - m % p));
        if (x > 2 * n || y > 2 * m) {
            continue;
        }
        int cur_sz = p * p;
        int cost = 0;
        for (int i = 1; i <= x; i += p) {
            for (int j = 1; j <= y; j += p) {
                int ones = get_area(i, j, i + p - 1, j + p - 1);
                int toggle = min(cur_sz - ones, ones);
                cost += toggle;
            }
        }
        ans = min(ans, cost);
    }
    cout << ans << '\n';
    
    return 0;
}