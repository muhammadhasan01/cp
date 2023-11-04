#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[n] == 1) {
        cout << "NO" << '\n';
        return;
    }
    int last = 0;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            continue;
        }
        int len = i - last - 1;
        ans.emplace_back(len);
        for (int rep = 0; rep < len; rep++) {
            ans.emplace_back(0);
        }
        last = i;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}