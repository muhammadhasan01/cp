#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long n;
long long a[N];
long long pre[N];
pair<long long, int> suf[N];
long long pos[N];
long long ans;
long long sum = 0;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ans = n * (n + 1) / 2;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        pos[i] = n + 1;
    }
    suf[n + 2].second = n + 2;
    suf[n + 1].second = n + 1;
    for (int i = n; i >= 1; i--) {
        suf[i].first = suf[i + 1].first + a[i];
        suf[i].second = i;
    }
    sort(suf + 1, suf + 1 + n + 2);
    for (int i = 0; i <= n; i++) {
        pre[i] = (i > 0 ? pre[i - 1] : 0) + a[i];
        int l = 1, r = n + 2, low = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suf[mid].first >= sum - pre[i]) {
                r = mid - 1;
                low = mid;
            } else {
                l = mid + 1;
            }
        }
        if (low != -1 && suf[low].first != sum - pre[i]) continue;
        l = 1, r = n + 2;
        int hgh = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suf[mid].first <= sum - pre[i]) {
                l = mid + 1;
                hgh = mid;
            } else {
                r = mid - 1;
            }
        }
        l = low, r = hgh;
        int at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (suf[mid].second >= i + 2) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        if (at == -1) continue;
        pos[i + 1] = min(pos[i + 1], suf[at].second - 1LL);
    }
    long long now = n + 1;
    for (int i = n; i >= 1; i--) {
        now = min(now, pos[i]);
        ans -= (n - now + 1);
    }
    cout << ans << '\n';

    return 0;
}