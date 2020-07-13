#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cout << 1 << (i == n ? '\n' : ' ');
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) solve();

    return 0;
}