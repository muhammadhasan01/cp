#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int dp[N];

void solve() {
    int n;
    cin >> n;
    int XOR = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        XOR ^= dp[x];
    }
    cout << (XOR > 0 ? 1 : 2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<int>> primes(N);
    for (int i = 2; i < N; i++) {
        if (primes[i].empty()) {
            for (int j = i; j < N; j += i) {
                primes[j].emplace_back(i);
            }
        }
        int x = i;
        for (int p : primes[i]) {
            while (x % p == 0) {
                dp[i]++;
                x /= p;
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