#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int q;
int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            sum += (1LL) * x;
        }
        long long l = 0, r = 1e7;
        long long ans = 0;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (mid * (1LL) * n >= sum) {
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
