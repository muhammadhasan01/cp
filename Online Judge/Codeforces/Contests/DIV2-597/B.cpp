#include <bits/stdc++.h>

using namespace std;

int tc;
int n, a, b, c;
string s;
char ans[105];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> a >> b >> c;
        cin >> s;
        int n = s.length();
        for (int i = 0; i < n; i++) ans[i] = '#';
        int x = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R' && b > 0) {
                ans[i] = 'P'; b--;
                x++;
            } else if (s[i] == 'P' && c > 0) {
                ans[i] = 'S'; c--;
                x++;
            } else if (s[i] == 'S' && a > 0) {
                ans[i] = 'R'; a--;
                x++;
            }
        }
        if (x >= (n + 1) / 2) {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                if (ans[i] == '#') {
                    if (a > 0) {
                        ans[i] = 'R'; a--;
                    } else if (b > 0) {
                        ans[i] = 'P'; b--;
                    } else if (c > 0) {
                        ans[i] = 'S'; c--;
                    }
                }
                cout << ans[i];
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
