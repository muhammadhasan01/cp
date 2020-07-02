#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int tc;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        int le = 2e9, ri = -2e9;
        for (int i = 1; i <= n; i++) {
            int l, r;
            cin >> l >> r;
            le = min(le, r);
            ri = max(ri, l);
        }
        cout << max(0, ri - le) << '\n';
    }

    return 0;
}
