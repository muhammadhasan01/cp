#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int n;
long long x;
long long d[N];
long long pre[N], pref[N];

long long F(long long x) {
    return x * (x + 1) / 2;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;
    long long maks = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        maks = max(maks, d[i]);
    }
    if (maks >= x) {
        cout << F(maks) - F(maks - x) << '\n';
        return 0;
    }
    for (int i = n + 1; i <= 2 * n; i++) {
        d[i] = d[i - n];
    }
    n = 2 * n;
    for (int i = 1; i <= n; i++) {
        pre[i] = d[i] + pre[i - 1];
        pref[i] = F(d[i]) + pref[i - 1];
    }
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        int l = max(1, i - n + 1), r = i, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre[i] - pre[mid - 1] <= x) {
                r = mid - 1;
                pos = mid;
            } else {
                l = mid + 1;
            }
        }
        assert(pos != -1);
        long long dif = x - (pre[i] - pre[pos - 1]);
        if (d[pos - 1] - dif < 0) continue;
        long long curval = (pref[i] - pref[pos - 1]) + (F(d[pos - 1]) - F(d[pos - 1] - dif));
        ans = max(ans, curval);
    }
    cout << ans << '\n';

    return 0;
}