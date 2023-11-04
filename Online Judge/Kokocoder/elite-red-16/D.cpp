#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> p(N);
    for (int i = 2; i < N; i++) {
        if (p[i] > 0) {
            continue;
        }
        for (int j = i; j < N; j += i) {
            p[j] = i;
        }
    }
    vector<long long> dp(N + 1);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (x > 1) {
            int y = p[x];
            while (x % y == 0) {
                x /= y;
            }
            dp[y]++;
        }
    }
    for (int i = 1; i <= N; i++) {
        dp[i] += dp[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = min(l, N);
        r = min(r, N);
        cout << dp[r] - dp[l - 1] << '\n';
    }
    
    return 0;
}