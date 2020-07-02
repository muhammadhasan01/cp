#include <bits/stdc++.h>

using namespace std;

int tc;
long long x;

void solve() {
    cin >> x;
    int cnt = 0;
    while (x % 3 == 0) {
        x /= 3;
        cnt++;
    }
    int two = 0;
    while (x % 2 == 0) {
        x /= 2;
        two++;
    }
    if (x > 1 || two > cnt) {
        cout << -1 << '\n';
        return;
    }
    cout << 2 * cnt - two << '\n';
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