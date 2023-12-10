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
    vector<int> ans;
    while (a[0] != a[n - 1]) {
        if (a[0] % 2 == 1 && a[n - 1] % 2 == 0) {
            a[0] = (a[0] + 1) / 2;
            a[n - 1] = (a[n - 1] + 1) / 2;
            ans.emplace_back(1);
        } else {
            a[0] /= 2;
            a[n - 1] /= 2;
            ans.emplace_back(0);
        }
    }
    int len = (int) ans.size();
    cout << len << '\n';
    if (len > n) {
        return;
    }
    for (int i = 0; i < len; i++) {
        cout << ans[i] << " \n"[i == len - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}