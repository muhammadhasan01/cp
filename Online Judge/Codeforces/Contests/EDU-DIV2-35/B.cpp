#include <bits/stdc++.h>
using namespace std;

int n, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    int l = 1, r = min(a, b), ans = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a / mid + b / mid >= n) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
