#include <bits/stdc++.h>

using namespace std;

const long long INF = 4e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<long long> v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<long long> pre(n), suf(n);
    for (int i = 0; i < n; i++) {
        pre[i] = v[0] * a[i];
        if (i > 0) {
            pre[i] = max(pre[i], pre[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = v[2] * a[i];
        if (i + 1 < n) {
            suf[i] = max(suf[i], suf[i + 1]);
        }
    }
    long long ans = -INF;
    for (int i = 0; i < n; i++) {
        long long cur = v[1] * a[i];
        ans = max(ans, pre[i] + cur + suf[i]);
    }
    cout << ans << '\n';

    return 0;
}