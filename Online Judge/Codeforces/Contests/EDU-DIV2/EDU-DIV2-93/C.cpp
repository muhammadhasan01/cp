#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int tc;
int n;
int a[N], pre[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char c; cin >> c;
        a[i] = (int) (c - '0') - 1;
    }
    unordered_map<int, int> mp;
    int sum = 0;
    mp[0] = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i];
        ans += (1LL) * mp[sum]++;
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}