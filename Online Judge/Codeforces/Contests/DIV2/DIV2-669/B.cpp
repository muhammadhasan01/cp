#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int val = 0, cur = 1;
    vector<bool> vis(n + 1);
    for (int it = 1; it <= n; it++) {
        int cur = 0, pos = -1;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            int cur_gcd = __gcd(val, a[i]);
            if (cur_gcd > cur) {
                cur = cur_gcd;
                pos = i;
            }
        }
        assert(pos != -1);
        val = cur;
        vis[pos] = 1;
        cout << a[pos] << (it == n ? '\n' : ' ');
    }
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