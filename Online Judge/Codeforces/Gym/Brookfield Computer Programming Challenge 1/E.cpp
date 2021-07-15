#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n, q;
    cin >> n >> q;
    long long x = q;
    int cnt = 1;
    long long ans = 0;
    while (true) {
        if (x >= n) {
            ans += n * cnt;
            break;
        }
        ans += x * cnt;
        n -= x;
        x *= q;
        cnt++;
    }
    cout << ans << '\n';
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