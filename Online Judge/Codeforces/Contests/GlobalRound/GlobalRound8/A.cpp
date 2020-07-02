#include <bits/stdc++.h>

using namespace std;


int tc;
long long a, b, n;

void solve() {
    cin >> a >> b >> n;
    if (a < b) swap(a, b);
    if (a + b > n) {
        cout << 1 << '\n';
        return;
    }
    long long r1 = a, r2 = a + b;
    int ans = 1;
    while (max(r1, r2) <= n) {
        if (ans & 1) {
            r1 += r2;
        } else {
            r2 += r1;
        }
        ++ans;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}