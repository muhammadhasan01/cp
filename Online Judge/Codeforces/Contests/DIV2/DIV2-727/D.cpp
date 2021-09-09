#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end(), [&](auto& x, auto& y) {
        return x.second < y.second;
    });
    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i].first;
    }
    long long ans = 0;
    long long items = 0;
    for (int i = n; i >= 1; i--) {
        auto& [x, y] = a[i];
        long long z = pre[i - 1] + items;
        if (y <= z) {
            continue;
        }
        long long dif = min(x, y - z);
        ans += 2LL * dif;
        items += dif;
        x -= dif;
    }
    for (int i = 1; i <= n; i++) {
        auto& [x, y] = a[i];
        if (x == 0 || y <= items) {
            items += x;
            ans += x;
            continue;
        }
        long long dif = min(x, y - items);
        ans += 2LL * dif;
        items += dif;
        x -= dif;
        i--;
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