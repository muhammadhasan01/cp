#include <bits/stdc++.h>

using namespace std;

const int N = 5e6 + 5;

int p[N];
long long cnt[N];
long long dp[N];

void solve() {
    int a, b;
    cin >> a >> b;
    cout << dp[a] - dp[b] << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < N; i++) {
        if (p[i] == 0) {
            for (int j = i; j < N; j += i) {
                p[j] = i;
            }
        }
        cnt[i] = cnt[i / p[i]] + 1;
        dp[i] = dp[i - 1] + cnt[i];
    }
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}