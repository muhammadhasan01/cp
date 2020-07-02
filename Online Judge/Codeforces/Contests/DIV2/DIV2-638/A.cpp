#include <bits/stdc++.h>

using namespace std;

int tc;
int n;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        long long x = 0, y = 0;
        x += (1LL << n);
        for (int i = 1; i < n / 2; i++) {
            x += (1LL << i);
        }
        for (int i = n / 2; i < n; i++) {
            y += (1LL << i);
        }
        cout << abs(x - y) << '\n';
    }

    return 0;
}