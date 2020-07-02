#include <bits/stdc++.h>

using namespace std;

int tc;
int n, x, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x >> a >> b;
        if (a > b) swap(a, b);
        int dif = a - 1 + n - b;
        int cur = b - a;
        cout << cur + min(x, dif) << '\n';
    }

    return 0;
}
