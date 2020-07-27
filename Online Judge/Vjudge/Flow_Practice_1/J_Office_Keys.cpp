#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, p;
    cin >> n >> k >> p;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }
    sort(pos.begin(), pos.end());
    vector<int> key(k);
    for (int i = 0; i < k; i++) {
        cin >> key[i];
    }
    sort(key.begin(), key.end());
    auto can = [&](long long x) {
        int cur = 0;
        for (int i = 0; i < k; i++) {
            if (abs(pos[cur] - key[i]) + abs(key[i] - p) > x) continue;
            if (++cur == n) break;
        }
        return (cur == n);
    };
    long long l = 0, r = INF, ans = INF;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (can(mid)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';

    return 0;
}