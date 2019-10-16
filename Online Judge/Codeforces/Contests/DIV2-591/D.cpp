#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;
int q, n;
int a[N], l[N], r[N], dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            l[i] = inf;
            r[i] = -inf;
            dp[i] = 0;
        }

        vector<int> v(n);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            v[i - 1] = a[i];
            l[a[i]] = min(l[a[i]], i);
            r[a[i]] = max(r[a[i]], i);
        }

        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());

        int res = n, len = v.size();
        for (int i = len - 1; i >= 0; i--) {
            if (i + 1 == len || r[v[i]] >= l[v[i + 1]]) dp[i] = 1;
            else dp[i] = 1 + dp[i + 1];
            res = min(res, len - dp[i]);
        }
        cout << res << '\n';
    }

    return 0;
}
