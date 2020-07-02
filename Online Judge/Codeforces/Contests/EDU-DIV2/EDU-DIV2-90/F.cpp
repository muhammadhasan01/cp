#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const long long INF = 1e18;

int tc;
int n;
int a[N], b[N], c[4 * N];
long long pre[4 * N];

void solve() {
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum -= (1LL) * a[i];
    }
    a[n + 1] = a[1];
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        sum += (1LL) * b[i];
    }
    if (sum < 0) {
        cout << "NO" << '\n';
        return;
    }
    for (int i = 1, j = 1; i <= 4 * n; i += 2, j += 1) {
        if (j > n) j = 1;
        c[i] = -a[j];
        c[i + 1] = b[j];
    }
    for (int i = 1; i <= 2; i++) pre[i] = pre[i - 1] + (1LL) * c[i];
    long long res = pre[1];
    for (int i = 3; i <= 4 * n; i++) {
        pre[i] = pre[i - 1] + (1LL) * c[i];
        if (i % 2 == 0) {
            long long cur = pre[i] - res;
            if (cur < 0) {
                cout << "NO" << '\n';
                return;
            }
        } else {
            res = max(res, pre[i]);
        }
    }
    cout << "YES" << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}