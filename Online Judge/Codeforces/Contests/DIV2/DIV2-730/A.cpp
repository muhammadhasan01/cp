#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    long long dif = b - a;
    if (dif == 0) {
        cout << 0 << ' ' << 0 << '\n';
        return;
    }
    long long op = min(b % dif, dif - b % dif);
    cout << dif << ' ' << op << '\n';
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