#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int) s.length();

    auto able = [&](string& p) {
        int m = (int) p.length();
        int cnt = 0;
        for (int i = 0; i + m - 1 < n; i++) {
            if (s.substr(i, m) == p) {
                ++cnt;
            }
            if (cnt >= 2) {
                return true;
            }
        }
        return false;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        string cur = "";
        for (int j = i; j < n; j++) {
            cur += s[j];
            if (able(cur)) {
                ans = max(ans, (int) cur.size());
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}