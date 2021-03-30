#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long a, b;
    cin >> a >> b;
    long long res = (a + b);
    if (res & 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    cout << res / 2 << '\n';

    return 0;
}