#include <bits/stdc++.h>
using namespace std;

int q, n;
string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> n >> s >> t;
        vector<int> v(30);
        for (auto e : s) v[e - 'a']++;
        for (auto e : t) v[e - 'a']--;
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (v[i] != 0) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        int ans = 1e5;
        for (int i = 1; i <= n; i++) {
            int cnt = 0, p = i;
            for (int j = 1; j <= n; j++) {
                if (s[j - 1] == t[p - 1]) {
                    p++, cnt++;
                }
            }
            ans = min(ans, n - cnt);
        }
        cout << ans << '\n';
    }

    return 0;
}
