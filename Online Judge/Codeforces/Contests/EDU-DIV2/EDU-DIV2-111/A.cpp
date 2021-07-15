#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int k = 1, cnt = 0;
    while (n > 0) {
        n = max(0, n - k);
        k += 2;
        cnt++;
    }
    cout << cnt << '\n';
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