#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, s;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int mid = (n + 1)/2;
    a[n + 1] = 1e9 + 10;
    a[0] = -1;
    long long ans = 0;
    if (a[mid] == s) {
        cout << ans << '\n';
    } else if (a[mid] < s) {
        for (int i = mid; i <= n; i++) {
            int len = i - mid + 1, dif = a[i + 1] - a[i];
            if (s >= a[i + 1]) {
                ans += (1LL) * dif * (1LL) * len;
                a[mid] = a[i + 1];
            } else if (s < a[i + 1]) {
                ans += (1LL) * (s - a[i]) * (1LL) * len;
                a[mid] = s;
            }
            if (a[mid] == s) break;
        }
        cout << ans << '\n';
    } else if (a[mid] > s) {
        for (int i = mid; i >= 1; i--) {
            int len = mid - i + 1, dif = a[i] - a[i - 1];
            if (s <= a[i - 1]) {
                ans += (1LL) * dif * (1LL) * len;
                a[mid] = a[i - 1];
            } else if (s > a[i - 1]) {
                ans += (1LL) * (a[i] - s) * (1LL) * len;
                a[mid] = s;
            }
            if (a[mid] == s) break;
        }
        cout << ans << '\n';
    }

    return 0;
}
