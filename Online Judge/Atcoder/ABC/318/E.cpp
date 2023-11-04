#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> cnt(n + 1);
    vector<long long> sum(n + 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int cur = cnt[a[i]];
        if (cur > 0) {
            ans += 1LL * cur * (i - 1) - sum[a[i]] - 1LL * cur * (cur - 1) / 2;
        }
        sum[a[i]] += i;
        cnt[a[i]]++;
    }
    cout << ans << '\n';
    
    return 0;
}