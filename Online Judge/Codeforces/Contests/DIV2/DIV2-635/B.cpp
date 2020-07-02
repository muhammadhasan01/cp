#include <bits/stdc++.h>

using namespace std;

const long long INF = 2e9;

int tc;
long long x, n, m;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> x >> n >> m;
        for (int i = 0; i < n; i++) {
            x = min(x, (x / 2) + 10);
        }
        x -= 10LL * m;
        cout << (x <= 0 ? "YES" : "NO") << '\n';
    }

    return 0;
}