#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cout << n / 2 + 1 << '\n';
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    if (n % 2 == 0) cout << n << '\n';

    return 0;
}