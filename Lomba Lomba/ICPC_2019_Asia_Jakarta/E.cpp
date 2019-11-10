#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, L, R, K;
int a[N], low[N], high[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> L >> R >> K;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    low[n] = L, high[n] = R;
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] < a[i + 1]) {
            low[i] = max(low[i + 1] - K, L);
            high[i] = high[i + 1] - 1;
        } else if (a[i] > a[i + 1]) {
            low[i] = low[i + 1] + 1;
            high[i] = min(high[i + 1] + K, R);
        } else {
            low[i] = low[i + 1];
            high[i] = high[i + 1];
        }
        if (low[i] > R || high[i] < L) {
            cout << -1 << '\n';
            return 0;
        }
    }
    a[0] = 2e9;
    for (int i = 1, cur = 0; i <= n; i++) {
        if (a[i - 1] > a[i]) {
            cur = max(cur - K, low[i]);
        } else if (a[i - 1] < a[i]) {
            cur = max(cur + 1, low[i]);
        }
        cout << cur << (i == n ? '\n' : ' ');
    }

    return 0;
}
