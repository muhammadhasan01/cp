#include <bits/stdc++.h>

using namespace std;

const long long K = 16;

long long fact[K];

void solve() {
    long long n;
    cin >> n;
    int ans = INT_MAX;
    for (int i = 0; i < (1 << K); i++) {
        long long cur = 0;
        int cnt = 0;
        for (int j = 0; j < K; j++) {
            if (i & (1 << j)) {
                cur += fact[j];
                ++cnt;
            }
        }
        if (cur <= n) {
            ans = min(ans, cnt + __builtin_popcountll(n - cur));
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    fact[0] = 1;
    for (int i = 1; i < K; i++) {
        fact[i] = 1LL * (i + 1) * fact[i - 1];
    }

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}