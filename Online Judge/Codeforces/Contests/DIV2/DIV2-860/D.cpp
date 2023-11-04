#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[0] == 0 && a[n - 1] == 0) {
        cout << "No" << '\n';
        return;
    }
    long long sum = 0;
    vector<int> ans(n);
    for (int l = 0, r = n - 1, i = 0; l <= r; i++) {
        if (sum >= 0) {
            ans[i] = a[l];
            sum += a[l];
            l++;
        } else {
            ans[i] = a[r];
            sum += a[r];
            r--;
        }
    }
    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; tt++) {
        solve();
    }
    
    return 0;
}