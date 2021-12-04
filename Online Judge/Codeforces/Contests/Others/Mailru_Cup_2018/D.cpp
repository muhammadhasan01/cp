#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int maxi = (1 << k) - 1;
    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    map<int, int> mp;
    mp[0]++;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = (a[i] ^ pre[i - 1]);
        int val = min(pre[i], (pre[i] ^ maxi));
        mp[val]++;
    }
    auto F = [&](long long x) {
        return x * (x - 1) / 2;
    };
    long long ans = 0;
    for (auto [val, cnt] : mp) {
        int m = cnt / 2;
        ans += F(m) + F(cnt - m);
    }
    cout << 1LL * n * (n + 1) / 2 - ans << '\n';

    return 0;
}