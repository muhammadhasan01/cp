#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int INF = 2e9;

int n, a, b;
char s[N];

void solve() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector<pair<char, int>> v;
    int cnt = 0;
    char cc = s[1];
    for (int i = 1; i <= n; i++) {
        if (cc == s[i]) {
            cnt++;
        } else {
            v.emplace_back(cc, cnt);
            cnt = 1;
            cc = s[i];
        }
    }
    v.emplace_back(cc, cnt);
    int ans = n * (a + b);
    for (int it = 0; it < 2; it++) {
        int len = 0, cur = 0;
        for (auto [x, y] : v) {
            int num = x - '0';
            if (num != it) {
                continue;
            }
            cur += y * a + b;
            len += y;
        }
        if (n - len > 0) cur += (n - len) * a + b;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        solve();
    }

    return 0;
}