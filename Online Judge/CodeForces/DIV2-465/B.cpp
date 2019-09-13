#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int x = 0, y = 0;
    bool f1 = false, f2 = false;
    int ans = 0;
    for (auto e : s) {
        if (e == 'U') {
            y++;
        } else if (e == 'R') {
            x++;
        }
        if (x > y) {
            if (f2) {
                f2 = false;
                ans++;
            }
            f1 = true;
        }
        if (x < y) {
            if (f1) {
                f1 = false;
                ans++;
            }
            f2 = true;
        }
    }
    cout << ans << '\n';

    return 0;
}
