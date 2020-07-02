#include <bits/stdc++.h>

using namespace std;

int tc;
long long n, m;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> m;
        if (n > m) swap(n, m);
        if (n == 1) {
            cout << (m + 1) / 2 << "\n";
        } else if (n == 2) {
            cout << m << '\n';
        } else if (n == 3) {
            cout << m + (m + 1) / 2 << '\n';
        } else if (n == 4) {
            cout << 2 * m << '\n';
        } else if (n & 1) {
            cout << (n / 2) * m + (m + 1) / 2 << '\n';
        } else {
            cout << (n / 2) * m << '\n';
        }
    }

    return 0;
}