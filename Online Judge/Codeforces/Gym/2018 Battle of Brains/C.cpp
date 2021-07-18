#include <bits/stdc++.h>

using namespace std;

void solve() {
    long double r;
    cin >> r;
    cout << fixed << setprecision(4) << r * r / 4 << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case " << T << ": ";
        solve();
    }

    return 0;
}