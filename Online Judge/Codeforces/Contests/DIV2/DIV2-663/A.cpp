#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << i << (i == n ? '\n' : ' ');
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