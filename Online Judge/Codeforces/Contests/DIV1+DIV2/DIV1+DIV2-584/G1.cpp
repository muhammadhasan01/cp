#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
int a[N], f[N], last[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = i;
        f[a[i]]++;
    }
    int le = 1, ri = 1, lmaks = -1, maks = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        lmaks = max(lmaks, last[a[i]]);
        maks = max(maks, f[a[i]]);
        ri = i;
        if (lmaks == i) {
            ans += (ri - le + 1) - (maks);
            le = i + 1;
            maks = 0;
        }
    }
    cout << ans << '\n';

    return 0;
}
