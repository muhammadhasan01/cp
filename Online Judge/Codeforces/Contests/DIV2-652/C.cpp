#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n, k;
int w[N];
long long a[N];

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<long long>());
    for (int i = 1; i <= k; i++) {
        cin >> w[i];
    }
    sort(w + 1, w + 1 + k);
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += a[i];
    }
    int pos = 1;
    for (int i = 1; i <= k; i++) {
        if (w[i] == 1) {
            pos = i + 1;
            ans += a[i];
        } else {
            break;
        }
    }
    int j = k;
    for (int i = pos; i <= k; i++) {
        j += (w[i] - 1);
        ans += a[j];
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