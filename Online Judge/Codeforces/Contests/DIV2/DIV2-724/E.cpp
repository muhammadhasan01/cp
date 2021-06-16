#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            ret = (ret * x) % M;
        }
        y = y >> 1;
        x = (x * x) % M;
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char cc;
            cin >> cc;
            cnt += (cc == '#');
        }
    }
    long long ans = modpow(2, cnt);
    if (cnt == n * m) {
        ans = ((ans - 1) % M + M) % M;
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