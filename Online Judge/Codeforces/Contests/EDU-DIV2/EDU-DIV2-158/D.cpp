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
    vector<pair<long long, int>> suf(n);
    {
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] + i;
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = {b[i], i};
            if (i + 1 < n) {
                suf[i] = max(suf[i], suf[i + 1]);
            }
        }
    }
    vector<pair<long long, int>> pre(n);
    {
        vector<long long> b(n);
        for (int i = 0; i < n; i++) {
            b[i] = a[i] - i;
        }
        for (int i = 0; i < n; i++) {
            pre[i] = {b[i], i};
            if (i > 0) {
                pre[i] = max(pre[i], pre[i - 1]);
            }
        }
    }
    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long need = a[i];
        if (i > 0) {
            int j = pre[i - 1].second;
            need = max(need, a[j] + (n - i - 1) + (i - j));
        }
        if (i + 1 < n) {
            int j = suf[i + 1].second;
            need = max(need, a[j] + i + (j - i));
        }
        ans = min(ans, need);
    }
    cout << ans << '\n';

    return 0;
}