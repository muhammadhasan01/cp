#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, a[N];
long long ans, res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        if (a[i] & 1) {
            if (a[i] >= 3) {
                ans++;
                a[i] -= 3;
            } else if (res > 0) {
                res--;
                ans++;
            }
        }
        res += (a[i] / 2);
    }
    ans += (res * 2) / 3;
    cout << ans << '\n';

    return 0;
}
