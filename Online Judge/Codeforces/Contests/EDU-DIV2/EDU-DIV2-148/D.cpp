#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, q;
    cin >> n >> q;
    long long sum = 0;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin() + 1, a.end());
    vector<long long> f(n + 1, INF);
    for (int i = 1; i <= n; i++) {
        f[i] = min(f[i - 1], a[i]) + 1;
    }
    while (q--) {
        int k;
        cin >> k;
        if (k < n) {
            cout << min(f[k], a[k + 1]) << ' ';
        } else {
            long long ans = 0;
            long long s = sum;
            if ((k - n) % 2 == 0) {
                ans = f[n] + (k - n);
                s += 1LL * n * (k + k - n + 1) / 2 - (k - n) / 2;
            } else {
                ans = min(f[n - 1] + k - n + 1, a[n]);
                s += 1LL * (n - 1) * (k + k - n + 2) / 2 - (k - n + 1) / 2;
            }
            cout << min(ans, s / n) << ' ';
        }
    }
    cout << '\n';
    
    return 0;
}