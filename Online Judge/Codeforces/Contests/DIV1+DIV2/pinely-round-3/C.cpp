#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    set<long long> R;
    for (int i = 0; i < n; i++) {
        long long r;
        cin >> r;
        R.emplace(r);
    }
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(l.rbegin(), l.rend());
    vector<long long> dif(n);
    for (int i = 0; i < n; i++) {
        auto it = R.upper_bound(l[i]);
        dif[i] = *it - l[i];
        R.erase(it);
    }
    sort(dif.begin(), dif.end());
    sort(c.rbegin(), c.rend());
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dif[i] * c[i];
    }
    cout << ans << '\n';
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