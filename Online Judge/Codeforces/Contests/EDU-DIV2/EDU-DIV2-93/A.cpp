#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 5;

int tc;
int n, a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[1] + a[2] > a[n]) {
        cout << -1 << '\n';
    } else {
        cout << 1 << ' ' << 2 << " " << n << '\n';
    }
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