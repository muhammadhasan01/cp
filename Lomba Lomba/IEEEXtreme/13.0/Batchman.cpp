#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, k;
int a[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int mmax = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mmax = max(mmax, a[i]);
        int kk = a[i];
        for (int i = 1; i * i <= kk; i++) {
            if (kk % i == 0) {
                cnt[i]++;
                if (i * i != kk) cnt[kk / i]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= mmax; i++) {
        //cerr << i << " => " << cnt[i];
        if (cnt[i] > 0) {
            bool ok = true;
            for (int j = i * 2; j <= mmax; j += i) {
                if (cnt[j] == cnt[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                //cerr << " => " << "OK";
                ans++;
            }
        }
        // cerr << '\n';
    }
    cout << ans << '\n';

    return 0;
}
