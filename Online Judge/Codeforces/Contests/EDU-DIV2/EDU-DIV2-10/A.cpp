#include <bits/stdc++.h>

using namespace std;

long long h1, h2;
long long a, b;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> h1 >> h2 >> a >> b;
    h1 += 8 * a;
    if (h1 >= h2) {
        cout << 0 << '\n';
        return 0;
    }
    if (b >= a) {
        cout << -1 << '\n';
        return 0;
    }
    h1 -= 12 * b;
    int ans = 1;
    while (1) {
        h1 += 12 * a;
        if (h1 >= h2) break;
        h1 -= 12 * b;
        ++ans;
    }
    cout << ans << '\n';

    return 0;
}