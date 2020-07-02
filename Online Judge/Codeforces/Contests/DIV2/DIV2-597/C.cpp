#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int M = 1e9 + 7;
string s;
ll dp[N], ans = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    for (auto e : s) {
        if (e == 'm' || e == 'w') {
            cout << 0 << '\n';
            return 0;
        }
    }

    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= N - 5; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= M;
    }

    int n = s.length();
    s = '#' + s;

    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'n') {
            k++;
        } else {
            ans = (ans * dp[k]) % M;
            k = 0;
        }
    }
    ans = (ans * dp[k]) % M;
    k = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'u') {
            k++;
        } else {
            ans = (ans * dp[k]) % M;
            k = 0;
        }
    }
    ans = (ans * dp[k]) % M;
    cout << (ans % M + M) % M << '\n';

    return 0;
}
