#include <bits/stdc++.h>

using namespace std;

int tc;
string s;
int n;

char change(char CC) {
    if (CC == '1') return '0';
    return '1';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        n = s.length();
        bool flag = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << s << '\n';
            continue;
        }
        string ans = s.substr(0, 1);
        for (int i = 1; i < n; i++) {
            if (ans.back() == s[i]) {
                ans += change(s[i]);
                ans += s[i];
            } else {
                ans += s[i];
            }
        }
        cout << ans << '\n';
    }

    return 0;
}