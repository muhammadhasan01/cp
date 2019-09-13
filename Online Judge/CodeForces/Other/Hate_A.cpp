#include <bits/stdc++.h>
using namespace std;

string s;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    n = s.length();
    string ans = "";
    int cnt = 0, pos = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            pos = i;
            cnt++;
        } else {
            ans += s[i];
        }
    }
    n = ans.length();
    if (n % 2 == 0 && ans.substr(0, n / 2) == ans.substr(n / 2) && pos < n / 2 + cnt) {
        cout << s.substr(0, n / 2 + cnt) << '\n';
    } else {
        cout << ":(" << '\n';
    }

    return 0;
}
