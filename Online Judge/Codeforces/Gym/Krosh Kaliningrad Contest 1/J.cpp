#include <bits/stdc++.h>

using namespace std;
 
const int N = 300010;
 
int n, m;
int a[N];
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    if (m == 2) {
        for (int i = 1; i <= n; i++) {
            ans += a[i];
        }
    } else if (m == 3) {
        int cnt[3] = {0, 0, 0};
        for (int i = 1; i <= n; i++) cnt[a[i]]++;
        int posodd = (n + 1) / 2;
        if (cnt[2] <= posodd) ans += 2 * cnt[2];
        else ans += 2 * posodd + cnt[2] - posodd;
        ans += cnt[1];
    } else {
        int cnt[4] = {0, 0, 0, 0};
        for (int i = 1; i <= n; i++) cnt[a[i]]++;
        int posodd = (n + 1) / 2;
        if (cnt[2] > 0) {
            cnt[2]--;
            posodd--;
            ans += 2;
        }
        if (cnt[3] <= posodd) ans += 3 * cnt[3];
        else ans += 3 * posodd + cnt[3] - posodd;
        ans += cnt[1];
    }
    cout << ans << '\n';
    return 0;
}