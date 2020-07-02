#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
const int NN = N * (N + 1) / 2;
int n, m;
int a[N], b[N];
pair<long long, int> c[NN];
long long x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    cin >> x;
    int ans = 0;
    int p = 0;
    for (int i = 1; i <= n; i++) {
        long long cur = 0;
        for (int j = i; j <= n; j++) {
            cur += (1LL) * a[j];
            c[++p] = {cur, j - i + 1};
        }
    }
    sort(c + 1, c + 1 + p);
    vector<int> d(p + 3, 0);
    for (int i = 1; i <= p; i++) {
        d[i] = max(d[i - 1], c[i].second);
    }
    for (int i = 1; i <= m; i++) {
        long long cur = 0;
        for (int j = i; j <= m; j++) {
            cur += (1LL) * b[j];
            if (cur > x) break;
            int l = 1, r = p, pos = 0;
            long long fnd = x / cur;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (c[mid].first <= fnd) {
                    l = mid + 1;
                    pos = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (pos > 0) ans = max(ans, (j - i + 1) * d[pos]);
        }
    }
    cout << ans << '\n';

    return 0;
}
