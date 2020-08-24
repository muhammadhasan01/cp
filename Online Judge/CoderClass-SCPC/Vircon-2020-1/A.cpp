#include <bits/stdc++.h>

using namespace std;

const int M = 1e5 + 5;

int tc;
long long a[M];
long long n, m, k;

long long ceil(long long a, long long b) {
    return (a + b - 1) / b;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + m);
    long long ans = 0, pos = 1;
    long long rem = 1 % k;
    for (int i = 1; i <= m; i++) {
        long long x = a[i];
        if (x % k == rem) {
            ans += ceil(x - pos + 1, k);
            pos = x + 1;
            rem = (rem + 1) % k;
        } else {
            ++ans;
        }
    }
    ans += ceil(n - pos + 1, k);
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}