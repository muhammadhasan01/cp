#include <bits/stdc++.h>

using namespace std;

int q;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;
    while (q--) {
        cin >> s;
        int n = s.length();
        s = '#' + s;
        long long ans = 0;
        for (int len = 1; len <= n; len++) {
            map<string, int> m;
            for (int i = 1; i <= n; i++) {
                int j = i + len - 1;
                if (j > n) break;
                string k = s.substr(i, len);
                sort(k.begin(), k.end());
                ans += (1LL) * (m[k]++);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
