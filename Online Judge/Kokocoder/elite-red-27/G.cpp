#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    auto can = [&](int x) -> bool {
        long long up = 0;
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] % x;
            up += x - b[i];
        }
        sort(b.begin(), b.end());
        long long need = 0;
        for (int i = 0; i < n - 1; i++) {
            need += b[i];
            up -= x;
            if (up < 0) {
                break;
            }
            if (up == 0 && need <= k) {
                return true;
            }
        }
        return false;
    };

    int ans = 1;
    for (int i = 1; 1LL * i * i <= sum; i++) {
        if (sum % i == 0) {
            int j = sum / i;
            if (can(i)) {
                ans = max(ans, i);
            }
            if (j != i && can(j)) {
                ans = max(ans, j);
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}