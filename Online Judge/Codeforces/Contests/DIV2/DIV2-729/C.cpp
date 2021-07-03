#include <bits/stdc++.h>

using namespace std;

const long long M = 1e9 + 7;

vector<long long> pre;

void solve() {
    long long n;
    cin >> n;
    long long ans = n % M;
    for (long long x : pre) {
        if (x > n) {
            break;
        }
        ans = (ans + n / x) % M;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long cur = 1;
    for (long long i = 1; i <= 41; i++) {
        cur = cur * (i / __gcd(i, cur));
        pre.emplace_back(cur);
    }

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}