#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> cnt(30);
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        for (int it = 20; it >= 0; it--) {
            if (x & (1LL << it)) {
                ++cnt[it];
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = 0;
        for (int it = 20; it >= 0; it--) {
            if (cnt[it] == 0) continue;
            cnt[it]--;
            cur += (1LL << it);
        }
        ans += cur * cur;
    }
    cout << ans << '\n';

    return 0;
}