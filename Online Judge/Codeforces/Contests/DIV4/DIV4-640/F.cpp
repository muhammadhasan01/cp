#include <bits/stdc++.h>

using namespace std;

int tc;
int a, b, c;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> a >> b >> c;
        string ans = "";
        if (b > 0) {
            ans = "01";
            for (int i = 0; i < c; i++) {
                ans += "1";
            }
            for (int i = 1; i < b; i++) {
                if (i & 1) {
                    ans += "0";
                } else {
                    ans += "1";
                }
            }
            for (int i = 0; i < a; i++) {
                ans = "0" + ans;
            }
        } else if (b == 0) {
            if (a > 0) {
                ans = string(a + 1, '0');
            } else if (c > 0) {
                ans = string(c + 1, '1');
            }
        }
        cout << ans << '\n';
    }

    return 0;
}