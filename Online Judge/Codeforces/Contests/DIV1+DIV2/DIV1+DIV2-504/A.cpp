#include <bits/stdc++.h>

using namespace std;

int n, m;
string s, t;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;
    if (m < n - 1) {
        cout << "NO" << '\n';
        return 0;
    }
    bool inc = false;
    for (auto e : s) {
        if (e == '*') {
            inc = true;
            break;
        }
    }
    if (!inc) {
        cout << (s == t ? "YES" : "NO") << '\n';
        return 0;
    }
    if (m == n - 1) {
        bool flag = true;
        for (int i = 0, j = 0; i < n; i++) {
            if (s[i] == '*') continue;
            if (s[i] != t[j]) {
                flag = false;
                break;
            }
            ++j;
        }
        cout << (flag ? "YES" : "NO") << '\n';
        return 0;
    }
    int dif = m - n;
    bool flag = true;
    for (int i = 0, j = 0; i < n; i++) {
        if (s[i] == '*') {
            if (dif > 0) {
                --dif, --i;
            }
            ++j;
            continue;
        }
        if (s[i] != t[j]) {
            flag = false;
            break;
        }
        ++j;
    }
    cout << (flag ? "YES" : "NO") << '\n';

    return 0;
}