#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<long long> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    long long ans = 0;
    vector<long long> mins(n);
    for (int i = 0; i < n; i++) {
        ans += max(l[i], r[i]);
        mins[i] = min(l[i], r[i]);
    }
    sort(mins.begin(), mins.end(), greater<long long>());
    for (int i = 0; i < k - 1; i++) {
        ans += mins[i];
    }
    cout << ans + 1 << '\n';
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
