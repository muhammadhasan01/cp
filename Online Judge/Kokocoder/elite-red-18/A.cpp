#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> last(n);
    iota(last.begin(), last.end(), 0);
    for (int i = 1; i < n; i++) {
        if (a[i - 1] < 2 * a[i]) {
            last[i] = last[i - 1];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int len = i - last[i] + 1;
        if (len >= k + 1) {
            ++ans;
        }
    }
    cout << ans << '\n';
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