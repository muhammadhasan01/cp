#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long x;
    cin >> n >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long add = 0;
    long long ans = 0;
    for (int i = 0, len = n; i < n; i++, len--) {
        if (i - 1 >= 0) {
            sum -= a[i - 1];
        }
        long long cursum = sum + 1LL * len * add;
        if (cursum > x) {
            continue;
        }
        long long dif = x - cursum;
        long long days = dif / len;
        ans += 1LL * len * (days + 1);
        add += days + 1;
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