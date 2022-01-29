#include <bits/stdc++.h>

using namespace std;

void solve() {
    string str;
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] != 'p') {
            continue;
        }
        map<char, int> bk;
        for (int j = i - 1; j >= 0; j--) {
            bk[str[j]] = i;
        }
        map<char, int> fr;
        for (int j = i + 1; j < n; j++) {
            fr[str[j]] = j;
        }
        if (bk.count('e') && bk.count('z') && fr.count('c')) {
            cout << "YES" << '\n';
            return;
        }
        if (bk.count('z') && fr.count('e') && fr.count('c')) {
            if (fr['e'] < fr['c']) {
                cout << "YES" << '\n';
                return;
            }
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