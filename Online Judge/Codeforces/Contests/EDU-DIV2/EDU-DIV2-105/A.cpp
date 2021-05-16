#include <bits/stdc++.h>

using namespace std;

string str;

void solve() {
    cin >> str;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                int res = 0;
                bool ok = true;
                for (char cc : str) {
                    if (cc == 'A') cc = (i == 0 ? '(' : ')');
                    if (cc == 'B') cc = (j == 0 ? '(' : ')');
                    if (cc == 'C') cc = (k == 0 ? '(' : ')');
                    if (cc == '(') res++;
                    else res--;
                    if (res < 0) {
                        ok = false;
                        break;
                    }
                }
                if (ok && res == 0) {
                    cout << "YES" << '\n';
                    return;
                }
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