#include <bits/stdc++.h>

using namespace std;

const long long INF = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long n;
    cin >> n;
    
    auto can = [&](long long k) -> bool {
        long long x = n;
        long long eat = 0;
        int turn = 1;
        while (x > 0) {
            if (turn) {
                eat += min(x, k);
                if (2 * eat >= n) {
                    return true;
                }
                x -= k;
            } else {
                x -= x / 10;
            }
            turn ^= 1;
        }
        return 2 * eat >= n;
    };

    long long l = 1, r = INF, ans = -1;
    while (l <= r) {
        long long mid = (l + r) >> 1LL;
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