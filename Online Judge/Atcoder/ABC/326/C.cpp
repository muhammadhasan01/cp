#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i, r = n - 1, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] < a[i] + m) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        if (at != -1) {
            ans = max(ans, at - i + 1);
        }
    }
    cout << ans << '\n';

    return 0;
}