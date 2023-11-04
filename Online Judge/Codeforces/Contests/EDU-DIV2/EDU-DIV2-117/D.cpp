#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b, x;
    cin >> a >> b >> x;
    while (min(a, b) > 0) {
        if (a > b) {
            swap(a, b);
        }
        if (a <= x && x <= b && x % a == b % a) {
            cout << "YES" << '\n';
            return;
        }
        b %= a;
    }
    cout << "NO" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}