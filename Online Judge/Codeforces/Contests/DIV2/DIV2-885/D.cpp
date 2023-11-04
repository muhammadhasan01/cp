#include <bits/stdc++.h>

using namespace std;

long long F(long long st, long long move) {
    if (move == 0) {
        return 0;
    }
    if (st == 2) {
        long long cycle = move / 4;
        long long res = cycle * 20;
        move %= 4;
        while (move > 0) {
            res += st;
            st = (st + st) % 10;
            move--;
        }
        return res;
    }
    return st + F((st + st) % 10, move - 1);
}

void solve() {
    long long s, k;
    cin >> s >> k;
    long long ans = s * k;
    if ((s % 10) & 1) {
        s += (s % 10);
        k -= 1;
        ans = max(ans, s * k);
    }
    if (s % 10 == 0) {
        cout << ans << '\n';
        return;
    }

    auto get = [&](long long x) -> long long {
        return (s + F(s % 10, x)) * (k - x);
    };

    auto can = [&](long long x, int t) -> bool {
        return get(x * 4 + t) < get((x + 1) * 4 + t);
    };

    for (int t = 0; t < 4; t++) {
        long long l = 0, r = k / 4, at = -1;
        while (l <= r)  {
            long long mid = (l + r) >> 1;
            if (can(mid, t)) {
                l = mid + 1;
                at = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = max(ans, get(t));
        if (at != -1) {
            ans = max(ans, get((at + 1) * 4 + t));
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}