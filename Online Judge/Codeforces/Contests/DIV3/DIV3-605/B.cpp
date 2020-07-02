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
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for (auto e : s) {
            if (e == 'L') c1++;
            else if (e == 'R') c2++;
            else if (e == 'U') c3++;
            else if (e == 'D') c4++;
        }
        if (c3 == 0 || c4 == 0) {
            if (c1 > 0 && c2 > 0) {
                cout << 2 << '\n';
                cout << "LR" << '\n';
            } else {
                cout << 0 << '\n';
            }
        } else {
            if (c1 == 0 || c2 == 0) {
                cout << 2 << '\n';
                cout << "UD" << '\n';
            } else {
                cout << 2 * (min(c1, c2) + min(c3, c4)) << '\n';
                for (int i = 1; i <= min(c1, c2); i++) {
                    cout << "R";
                }
                for (int i = 1; i <= min(c3, c4); i++) {
                    cout << "D";
                }
                for (int i = 1; i <= min(c1, c2); i++) {
                    cout << "L";
                }
                for (int i = 1; i <= min(c3, c4); i++) {
                    cout << "U";
                }
                cout << '\n';
            }
        }
    }

    return 0;
}
