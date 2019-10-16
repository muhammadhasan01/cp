#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
const int M = 1e9 + 7;
int n;
int a[N], f[N], cnt[N];
long long dp[N];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int pos = 1, id = 0;
    while (pos != n + 1) {

        if (f[pos] == 0) f[pos] = ++id;

        if (++cnt[pos] & 1) {
            ans++;
            if (f[a[pos]] == 0) {
                pos = a[pos];
            } else {
                ans += (ans - dp[f[a[pos]] - 1]);
                ans %= M;
                pos++;
            }
        } else {
            ans++;
            pos++;
        }
        dp[id] = ans % M;
    }
    cout << (ans % M + M) % M << '\n';

    return 0;
}
