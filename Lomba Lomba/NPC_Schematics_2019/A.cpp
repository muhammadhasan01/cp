#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n;
int a[N];
int f[35], g[35];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j <= 30; j++) {
            bool b = (a[i] & (1 << j));
            if (b) {
                f[j] = 1;
            } else {
                g[j] = 1;
            }
        }
    }

    int ans = 0;
    for (int j = 0; j <= 30; j++) {
        if (f[j] && g[j]) {
            ans += (1 << j);
        }
    }
    cout << ans << '\n';

    return 0;
}
