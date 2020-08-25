#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;
const int K = 4e4;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto ceil = [&](long long x, long long y) {
        return (x + y - 1) / y;
    };
    auto check = [&](int k) {
        long long ret = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            long long res = ceil(a[i], k + 1);
            if (res * k > a[i]) {
                ok = false;
                break;
            }
            ret += res;
        }
        return (ok ? ret : INF);
    };
    long long ans = INF;
    for (int k = 1; k <= K; k++) {
        ans = min(ans, check(k));
        if (a[0] / k > 0) ans = min(ans, check(a[0] / k));
        if (a[0] / k - 1 > 0) ans = min(ans, check(a[0] / k - 1));
    }
    cout << ans << '\n';

    return 0;
}