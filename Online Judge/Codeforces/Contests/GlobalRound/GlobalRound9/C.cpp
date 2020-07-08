#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

int tc;
int n;
int a[N], pos[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    bool ok = false;
    for (int x = n; x >= 1; x--) {
        if (pos[x] == 1) break;
        if (pos[x] == n) {
            ok = true;
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
    while (tc--) {
        solve();
    }

    return 0;
}