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
            cout << "YES" << '\n';
        } else if (n == 2) {
            cout << (m == 2 ? "YES" : "NO") << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}