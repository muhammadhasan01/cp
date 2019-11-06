#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n;
long long x;
long long a[N];

bool get(int k) {
    for (int i = k; i <= n; i++) {
        long long res = a[i] - a[i - k];
        if (res >= x) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (get(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}
