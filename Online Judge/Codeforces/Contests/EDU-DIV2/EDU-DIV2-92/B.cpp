#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n, k, z;
long long a[N];
long long pre[N];
long long maks[N];

void solve() {
    cin >> n >> k >> z;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    long long sum = pre[k + 1];
    long long ans = sum;
    for (int i = 1; i < n; i++) {
        maks[i] = max(maks[i - 1], a[i + 1] + a[i]);
    }
    for (int it = 1; it <= z; it++) {
        int pos = k + 1 - 2 * it;
        if (pos <= 0) break;
        sum = pre[k + 1 - 2 * it] + (1LL) * it * maks[pos];
        ans = max(ans, sum);
    }
    cout << ans << '\n';
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