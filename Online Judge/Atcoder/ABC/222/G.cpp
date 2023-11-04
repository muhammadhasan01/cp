#include <bits/stdc++.h>

using namespace std;

void solve() {
    int k;
    cin >> k;
    if (k % 2 == 0) {
        k /= 2;
    }
    k *= 9;

    auto phi = [&](int x) -> int {
        int res = x;
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                while (x % i == 0) {
                    x /= i;
                }
                res -= res / i;
            }
        }
        if (x > 1) {
            res -= res / x;
        }
        return res;
    };

    auto divisors = [&](int x) -> vector<int> {
        vector<int> div;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                div.emplace_back(i);
                int j = x / i;
                if (i != j) {
                    div.emplace_back(j);
                }
            }
        }
        sort(div.begin(), div.end());
        return div;
    };

    auto binpow = [&](int x, int y, int mod) -> int {
        int res = 1;
        while (y > 0) {
            if (y & 1) {
                res = (1LL * res * x) % mod;
            }
            y >>= 1;
            x = (1LL * x * x) % mod;
        }
        return res;
    };

    for (int x : divisors(phi(k))) {
        if (binpow(10, x, k) == 1) {
            cout << x << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}