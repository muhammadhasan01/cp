#include <bits/stdc++.h>

using namespace std;

int tc;
string s;

char c(char x) {
    if (x == 'a') return 'b';
    if (x == 'b') return 'c';
    if (x == 'c') return 'a';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        int n = s.size();
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1] && s[i] != '?') {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (i - 1 >= 0) {
                    s[i] = c(s[i - 1]);
                    if (i + 1 < n && s[i + 1] == s[i]) s[i] = c(s[i]);
                } else {
                    s[i] = 'a';
                    if (i + 1 < n && s[i + 1] == s[i]) s[i] = c(s[i]);
                }
            }
        }
        cout << s << '\n';
    }

    return 0;
}
