#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    string t;
    cin >> t;

    auto isSub = [&](string& x, string& y) -> bool {
        int p = x.length();
        int q = y.length();
        if (p + 1 != q) {
            return false;
        }
        int pos = 0;
        for (int i = 0; i < q && pos < p; i++) {
            if (x[pos] == y[i]) {
                ++pos;
            }
        }
        return pos == p;
    };

    auto same = [&](string& s) -> bool {
        return s == t;
    };

    auto ins = [&](string& s) -> bool {
        return isSub(s, t);
    };

    auto del = [&](string& s) -> bool {
        return isSub(t, s);
    };

    auto changed = [&](string& s) -> bool {
        if (s.length() != t.length()) {
            return false;
        }
        int cnt = 0;
        for (int i = 0; i < (int) s.length(); i++) {
            if (s[i] != t[i]) {
                ++cnt;
            }
        }
        return cnt == 1;
    };

    auto check = [&](string& s) -> bool {
        return same(s) || ins(s) || del(s) || changed(s);
    };

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (check(s)) {
            ans.emplace_back(i);
        }
    }
    int m = (int) ans.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
    
    return 0;
}