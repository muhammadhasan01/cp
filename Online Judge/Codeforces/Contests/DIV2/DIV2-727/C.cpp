#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k, x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<long long, int>> difs;
    vector<bool> good(n);
    for (int i = 1; i < n; i++) {
        long long dif = a[i] - a[i - 1];
        if (dif <= x) {
            good[i] = true;
            continue;
        }
        dif = dif - x;
        long long need = (dif + x - 1) / x;
        difs.emplace_back(need, i);
    }
    sort(difs.begin(), difs.end());
    int len = difs.size();
    for (int i = 0; i < len; i++) {
        auto [dif, pos] = difs[i];
        if (dif > k) {
            k = 0;
            break;
        }
        k -= dif;
        good[pos] = true;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (good[i]) {
            continue;
        }
        ans++;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}