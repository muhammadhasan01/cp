#include<bits/stdc++.h>
using namespace std;

int n, a, b, c, t;
int ar[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b >> c >> t;
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
    }
    if (c > b) {
        int ans = n * a;
        for (int i = 1; i <= n; i++) {
            ans += (t - ar[i]) * (c - b);
        }
        cout << ans << '\n';
    } else {
        cout << n * a << '\n';
    }

    return 0;
}
