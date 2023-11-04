#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mx = t[i] + w;
        int at = i;
        int cnt = 0;
        for (int j = i; j < n && cnt < k; j++, cnt++) {
            if (t[j] > mx) {
                if (t[j] - mx > d) {
                    break;
                }
            }
            at = j;
        }
        i = at;
        ans++;
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