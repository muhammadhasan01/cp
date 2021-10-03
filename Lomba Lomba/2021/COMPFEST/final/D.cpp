#include <bits/stdc++.h>

using namespace std;

const vector<string> BACK = {"25", "50", "75", "00"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int len = s.length();
    if (len == 1) {
        if (s[0] == '0' || s[0] == 'X' || s[0] == '_') {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
        return 0;
    }
    if (s[0] == '0') {
        cout << 0 << '\n';
        return 0;
    }
    if (len == 2) {
        int cnt = 0;
        for (char cc : s) {
            if (cc == 'X') {
                ++cnt;
            }
        }
        if (cnt == 2) {
            cout << 0 << '\n';
            return 0;
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            bool ok = true;
            for (int j = 0; j < len; j++) {
                if (s[j] == 'X' || s[j] == '_') {
                    continue;
                }
                if (s[j] != BACK[i][j]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans++;
            }
        }
        cout << ans << '\n';
        return 0;
    }
    bool any_x = false;
    for (char cc : s) {
        if (cc == 'X') {
            any_x = true;
        }
    }
    auto get_back = [&](string& x) -> int {
        int ret = 0;
        for (int i = 0; i < 4; i++) {
            bool ok = true;
            for (int j = len - 2, k = 0; j < len; j++, k++) {
                if (x[j] == '_') {
                    continue;
                }
                if (x[j] != BACK[i][k]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ret++;
            }
        }
        return ret;
    };
    long long ans = 0;
    if (any_x) {
        for (int x = 0; x < 10; x++) {
            string t = s;
            for (char& cc : t) {
                if (cc == 'X') {
                    cc = char(int('0') + x);
                }
            }
            if (t[0] == '0') {
                continue;
            }
            long long bck = get_back(t);
            long long frt = 1;
            for (int i = 0; i <= len - 3; i++) {
                if (t[i] == '_') {
                    if (i == 0) {
                        frt = (frt * 9);
                    } else {
                        frt = (frt * 10);
                    }
                }
            }
            ans += frt * bck;
        }
    } else {
        long long bck = get_back(s);
        long long frt = 1;
        for (int i = 0; i <= len - 3; i++) {
            if (s[i] == '_') {
                if (i == 0) {
                    frt = (frt * 9);
                } else {
                    frt = (frt * 10);
                }
            }
        }
        ans += frt * bck;
    }
    cout << ans << '\n';
    
    return 0;
}