#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n, m;
int power[N];
int bucket[N], dp[N], par[N], root;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> power[i];
    }
    root = sqrt(n) + 1;
    for (int i = n; i >= 1; i -= root) {
        for (int j = i; j > max(i - root, 0); j--) {
            bucket[j] = i;
            if (j + power[j] > n) {
                dp[j] = 1;
                par[j] = j;
            } else if (j + power[j] <= i) {
                dp[j] = 1 + dp[j + power[j]];
                par[j] = par[j + power[j]];
            } else {
                dp[j] = 1;
                par[j] = j + power[j];
            }
        }
    }
    while (m--) {
        int tp;
        cin >> tp;
        if (tp == 0) {
            int a, b;
            cin >> a >> b;
            power[a] = b;
            for (int i = bucket[a]; i > max(bucket[a] - root, 0); i--) {
                if (i + power[i] > n) {
                    dp[i] = 1;
                    par[i] = i;
                } else if (i + power[i] <= bucket[a]) {
                    dp[i] = 1 + dp[i + power[i]];
                    par[i] = par[i + power[i]];
                } else {
                    dp[i] = 1;
                    par[i] = i + power[i];
                }
            }
        } else {
            int a;
            cin >> a;
            int ans = dp[a], lastpar = a;
            while (par[a] != a) {
                if (bucket[a] != bucket[par[a]])
                    ans += dp[par[a]];
                a = par[a];
                lastpar = a;
            }
            cout << lastpar << " " << ans << '\n';
        }
    }

    return 0;
}