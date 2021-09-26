#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int ans = 0;
    int pre = 0, len = 0;
    map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
        char cc = s[i];
        len++;
        if (cc == '(') {
            pre++;
            mp[pre] = i;
        } else if (cc == ')') {
            pre--;
            if (pre < 0) {
                pre = 0;
                len = 0;
            } else if (pre == 0) {
                ans = max(ans, len);
                len = 0;
            } else if (pre > 0) {
                ans = max(ans, i - mp[pre + 1] + 1);
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt;
    cin >> tt;
    for (int t = 1; t <= tt; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}