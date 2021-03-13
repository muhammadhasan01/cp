#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
long long b[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] < i - 1) {
            cout << "NO" << '\n';
            return;
        }
        b[i + 1] += (b[i] - i + 1);
    }
    cout << "YES" << '\n';
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