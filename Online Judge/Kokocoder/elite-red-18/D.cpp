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
    }
    vector<long long> pre(n + 2);
    vector<long long> suf(n + 2);
    for (int i = 1; i <= n; i++) {
        pre[i] = (pre[i - 1] ^ a[i]);
    }
    for (int i = n; i >= 1; i--) {
        suf[i] = (suf[i + 1] ^ a[i]);
    }

    auto getMaxXOR = [&](long long x, long long y) -> long long {
        long long ret = (x ^ y);
        long long sum = 0;
        for (int i = 60; i >= 0; i--) {
            if (y & (1LL << i)) {
                long long val = (1LL << i) - 1;
                long long cur = ((x ^ sum) | val);
                ret = max(ret, cur);
                sum |= (1LL << i);
            }
        }
        return ret;
    };

    long long ans = pre[n];
    for (int i = 1; i <= n; i++) {
        long long res = (pre[i - 1] ^ suf[i + 1]);
        ans = max(ans, getMaxXOR(res, a[i]));
    }
    cout << ans << '\n';
    
    return 0;
}