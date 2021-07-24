#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, t;

bool check(int pos) {
    if (s[pos] != t[0]) {
        return false;
    }
    for (int r = 0; r <= m; r++) {
        int l = m - r;
        int i = pos, j = 0;
        bool ok = true;
        for (int it = 0; it < r; it++) {
            if (i >= n) {
                ok = false;
                break;
            }
            if (s[i++] != t[j++]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            continue;
        }
        if (r > 0) {
            i--;
        }
        for (int it = 0; it < l; it++) {
            if (--i < 0) {
                ok = false;
                break;
            }
            if (s[i] != t[j++]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> s >> t;
    n = s.length();
    m = t.length();
    for (int i = 0; i < n; i++) {
        if (check(i)) {
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
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