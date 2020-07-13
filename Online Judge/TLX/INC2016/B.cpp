#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n;
long long k;
long long a[N];

int solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        int l = i + 1, r = n, at = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] - a[i] <= k) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, at - i + 1);
    }
    return ans;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}