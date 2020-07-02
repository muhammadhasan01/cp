#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e9;

int tc;
long long a, b, c;

void solve() {
    cin >> a >> b >> c;
    cout << (a < c ? 1 : -1) << ' ';
    cout << (a * b > c ? b : -1) << '\n';
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