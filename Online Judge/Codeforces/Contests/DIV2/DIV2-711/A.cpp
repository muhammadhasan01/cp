#include <bits/stdc++.h>

using namespace std;

long long n;

long long get(long long x) {
    long long ret = 0;
    while (x > 0) {
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

void solve() {
    cin >> n;
    for (int it = 0; it < 10; it++) {
        long long s = get(n);
        if (__gcd(n, s) > 1) {
            cout << n << '\n';
            return;
        }
        ++n;
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}