#include <bits/stdc++.h>

using namespace std;

int tc;
long long a, b, c, d;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c >> d;
        if (a == c || b == d) {
            cout << 1 << '\n';
        } else {
            cout << (c - a) * (d - b) + 1 << '\n';
        }
    }

    return 0;
}