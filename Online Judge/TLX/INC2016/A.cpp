#include <bits/stdc++.h>

using namespace std;

int tc;
string s, p;

void solve() {
    cin >> p >> s;
    int ls = s.size(), lp = p.size();
    if (lp > ls) {
        cout << "NO" << '\n';
        return;
    }
    int pos = 0;
    for (int i = 0; i < ls; i++) {
        if (s[i] == p[pos]) {
            if (++pos == lp) break;
        } else {
            pos = 0;
        }
    }
    cout << (pos == lp ? "YES" : "NO") << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": "; solve();
    }

    return 0;
}