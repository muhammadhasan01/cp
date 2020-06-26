#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int tc;
int n;
long long a[N];
long long pre[N];

void solve() {
    cin >> n;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i & 1) ans += a[i];
    }
    long long res = ans;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + (i & 1 ? a[i] : -a[i]);
    }
    priority_queue<long long> pq[2];
    for (int i = 0; i <= 1; i++) pq[i].emplace(pre[i]);
    for (int i = 2; i <= n; i++) {
        long long dif = pre[i] - pq[(i & 1)].top();
        long long cur = res - dif;
        ans = max(ans, cur);
        pq[(i & 1)].emplace(pre[i]);
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