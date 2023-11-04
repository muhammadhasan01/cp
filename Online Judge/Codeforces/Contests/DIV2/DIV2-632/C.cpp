#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int last = 0;
    unordered_map<long long, int> mp;
    mp[0] = 0;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (mp.count(a[i]) > 0) {
            last = max(last, mp[a[i]] + 1);
        }
        mp[a[i]] = i;
        ans += (i - last);
    }
    cout << ans << '\n';
    
    return 0;
}