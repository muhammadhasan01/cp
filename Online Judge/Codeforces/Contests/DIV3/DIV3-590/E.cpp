#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, m;
int a[N];
long long dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    long long res = 0, dif = 0;
    vector<pair<int,int>> v(m - 1);
    vector<int> w(m - 1);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            for (int j = 1; j <= m - 1; j++) {
                res += (1LL) * abs(a[j] - a[j + 1]);
                int k1 = min(a[j], a[j + 1]);
                int k2 = max(a[j], a[j + 1]);
                if (k1 == k2) {
                    v[j - 1] = {0, 0};
                    w[j - 1] = 0;
                } else {
                    v[j - 1] = {k1, k2};
                    w[j - 1] = k2;
                    dp[k2] += (1LL) * k1 - (1LL) * abs(a[j] - a[j + 1]);
                }
            }
            sort(v.begin(), v.end());
            sort(w.begin(), w.end());
        } else {
            dif = 0;
            int l = 0, r = m - 2, pos = -1;
            // x and higher x
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (v[mid].first >= i) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            int len = 0;
            if (pos != -1 & v[pos].first == i) {
                l = 0, r = m - 2;
                int pos2 = -1;
                while (l <= r) {
                    int mid = (l + r) >> 1;
                    if (v[mid].first <= i) {
                        l = mid + 1;
                        pos2 = mid;
                    } else {
                        r = mid - 1;
                    }
                }
                len = pos2 - pos + 1;
                dif += (1LL) * len * (1LL) * (i - 1);
                // ok
            }
            int lenz = 0;
            if (pos != -1) lenz = m - 1 - pos;
            // higher x and lower x
            l = 0, r = m - 2, pos = -1;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (w[mid] > i) {
                    r = mid - 1;
                    pos = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (pos != -1) {
                dif -= (1LL) * (m - 1 - pos);
                dif += (1LL) * lenz;
            }
            // x and lower x
            dif += (1LL) * dp[i];
        }
        cout << res + dif << (i == n ? '\n' : ' ');
    }

    return 0;
}
