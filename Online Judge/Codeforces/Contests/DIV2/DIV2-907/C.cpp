#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long pre = 0;
    long long ans = LLONG_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        long long R = sum - pre;
        long long L = pre;
        if (R - L >= 0) {
            long long need = (R - L + 1) / 2;
            if (need <= a[i]) {
                long long cur = L + need + (need == a[i] ? 0 : 1) + (n - i - 1);
                ans = min(ans, cur);
            }
        }
        pre += a[i];
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