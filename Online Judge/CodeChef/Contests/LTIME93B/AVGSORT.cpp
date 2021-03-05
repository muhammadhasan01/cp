#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int cur = a[n];
    for (int i = n - 1; i >= 1; i--) {
        if (cur > a[i]) {
            cout << "Yes" << '\n';
            return;
        }
        cur = max(cur, a[i]);
    }
    cout << "No" << '\n';
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