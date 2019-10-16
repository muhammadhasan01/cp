#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
int n, p[N];
string s[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        p[i] = (int) s[i].size();
    }

    for (int i = n - 1; i >= 1; i--) {
        bool ok = true;
        for (int x = 0, y = 0; x < p[i] && y < p[i + 1]; x++, y++) {
            if (s[i][x] > s[i + 1][y]) {
                ok = false;
                p[i] = x;
                break;
            } else if (s[i][x] < s[i + 1][y]) {
                ok = false;
                break;
            }
        }
        if (ok && p[i] > p[i + 1]) p[i] = p[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        cout << s[i].substr(0, p[i]) << '\n';
    }

    return 0;
}
