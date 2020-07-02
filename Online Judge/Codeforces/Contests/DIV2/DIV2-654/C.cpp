#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, n, m;

void solve() {
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
        cout << "NO" << '\n';
        return;
    }
    cout << (min(a, b) < m ? "NO" : "YES") << '\n';
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