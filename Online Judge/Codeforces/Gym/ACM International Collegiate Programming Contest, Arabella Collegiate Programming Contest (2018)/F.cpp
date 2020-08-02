#include <bits/stdc++.h>

using namespace std;

const int K = 26;

int tc;
long long f[K + 5];

void solve() {
    long long res = 0;
    bool ok = false;
    for (int i = 0; i < K; i++) {
        cin >> f[i];
        if (f[i] > 1)
            res += 2;
        else if (!ok && f[i] == 1)
            ok = true, res++;
    }
    long long occ = 1;
    if (!ok) {
        long long l = 0, r = INF;
        while (l <= r) {
            long long mid = (l + r) >> 1;
            if (can_1(mid)) {
                l = mid + 1;
                occ = mid;
            } else {
                r = mid - 1;
            }
        }
    } else {
        
    }
    cout << res << " " << occ << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}