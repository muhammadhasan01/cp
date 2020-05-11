#include <bits/stdc++.h>

using namespace std;

int tc;
long long n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        if (n % 2 == 0) {
            cout << n / 2 - 1 << '\n';
        } else {
            cout << n / 2 << '\n';
        }
    }

    return 0;
}