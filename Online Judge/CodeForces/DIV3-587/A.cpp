#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < n - 1; i += 2) {
        int c1 = 0, c2 = 0;
        if (s[i] != 'a') c1++;
        else if (s[i] == 'a') c2++;
        if (s[i + 1] != 'b') c1++;
        else if (s[i + 1] == 'b') c2++;
        if (c1 > c2) {
            s[i] = 'b';
            s[i + 1] = 'a';
        } else {
            s[i] = 'a';
            s[i + 1] = 'b';
        }
        ans += min(c1, c2);
        c1 = c2 = 0;
    }
    cout << ans << '\n';
    cout << s << '\n';

    return 0;
}
