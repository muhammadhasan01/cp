#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k, f;
    cin >> n >> k >> f;
    vector<long long> bit(f);
    for (int i = 0; i < f; i++) {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++) {
            int num;
            cin >> num;
            --num;
            bit[i] |= (1LL << num);
        }
    }
    long long all = (1LL << n) - 1LL;
    int ans = 0;
    for (int mask = 0; mask < (1 << f); mask++) {
        long long bits = 0;
        for (int i = 0; i < f; i++) {
            if (mask & (1 << i)) {
                bits |= bit[i];
            }
        }
        long long cur = all - bits;
        int on = __builtin_popcountll(cur);
        if (on >= k) {
            ans = max(ans, __builtin_popcountll(mask));
        }
    }
    cout << ans << '\n';
    
    return 0;
}