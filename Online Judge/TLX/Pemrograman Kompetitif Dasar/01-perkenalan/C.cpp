#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string p;
    cin >> p;
    int len = p.length();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m = s.length();
        if (m < len - 1) {
            continue;
        }
        int x = m;
        for (int j = 0; j < len; j++) {
            if (p[j] == '*') {
                x = j - 1;
                break;
            }
            if (s[j] == p[j]) {
                continue;
            }
            break;
        }
        if (x == m) {
            continue;
        }
        int y = -1;
        for (int j = m - 1, k = len - 1; k >= 0; j--, k--) {
            if (p[k] == '*') {
                y = j + 1;
                break;
            }
            if (s[j] == p[k]) {
                continue;
            }
            break;
        }
        if (x >= y) {
            continue;
        }
        cout << s << '\n';
    }
    
    return 0;
}