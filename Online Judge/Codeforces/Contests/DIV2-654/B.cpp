#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, r;

void solve() {
    cin >> n >> r;
    if (n <= r) {
        cout << n * (n - 1) / 2 + 1LL << '\n';
    } else {
        cout << r * (r + 1) / 2 << '\n';
    }
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