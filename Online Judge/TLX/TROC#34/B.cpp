#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (n == 1) {
        cout << 2LL * a[0] - 1 << '\n';
        return 0;
    }
    long long sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += a[i];
    }
    long long dif = a[n - 1] - sum;
    if (dif <= 1) {
        cout << sum + a[n - 1] << '\n';
        return 0;
    }
    long long ans = 2 * sum + 2LL * dif - 1;
    cout << ans << '\n';
    
    return 0;
}