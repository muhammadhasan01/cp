#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> last(n + m + 2, -1);
    vector<int> cnt(n + m + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        last[a[i]] = 0;
    }
    for (int it = 1; it <= m; it++) {
        int p, v;
        cin >> p >> v;
        cnt[a[p]] += it - last[a[p]];
        last[a[p]] = -1;
        a[p] = v;
        last[a[p]] = it;
    }
    int len = m + 1;
    long long ans = 0;
    for (int i = 1; i <= n + m; i++) {
        cnt[i] += (last[i] != -1 ? len - last[i] : 0);
        long long cur = 1LL * cnt[i] * (len - cnt[i]);
        cur += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        ans += cur;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}