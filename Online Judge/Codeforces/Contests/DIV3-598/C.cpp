#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;
int n, m, d;
int ans[N], res[N], c[N], low[N], high[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> d;
    c[0] = c[m + 1] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
    }
    low[0] = high[0] = 0;
    for (int i = 1; i <= m; i++) {
        low[i] = low[i - 1] + c[i - 1];
    }
    low[m + 1] = high[m + 1] = n + 1;
    for (int i = m; i >= 1; i--) {
        high[i] = high[i + 1] - c[i];
    }
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        ans[i] = min(cur + d, high[i]);
        cur = ans[i] + c[i] - 1;
    }
    if (cur + d < n + 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int i = 1; i <= m; i++) {
            for (int j = ans[i]; j <= ans[i] + c[i] - 1; j++) {
                res[j] = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << res[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
