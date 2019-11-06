#include <bits/stdc++.h>

using namespace std;

int x, y;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> y;
    string s;
    cin >> s;
    for (auto e : s) {
        if (e == 'U') {
            y++;
        } else if (e == 'D') {
            y--;
        } else if (e == 'L') {
            x--;
        } else if (e == 'R') {
            x++;
        }
    }
    cout << x << " " << y << '\n';

    return 0;
}
