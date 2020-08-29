#include <bits/stdc++.h>

using namespace std;


int tc;
long long a, b;

void solve() {
    cin >> a >> b;
    long long haha = a + b;
    bool ok = (a - b == 1);
    for (long long i = 2; i * i <= haha; i++) {
        if (haha % i == 0) {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
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