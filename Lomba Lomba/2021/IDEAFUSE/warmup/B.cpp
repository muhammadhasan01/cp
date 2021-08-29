#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string& s) {
    int len = s.size();
    for (int i = 0, j = len - 1; i < len; i++, j--) {
        if (i > j) {
            break;
        }
        if (s[i] != s[j]) {
            return false;
        }
    } 
    return true;
}

void solve() {
    string str;
    cin >> str;
    string ans = "";
    if (is_palindrome(str)) {
        ans = str;
    }
    int len = str.size();
    for (int i = 0; i <= len; i++) {
        for (int it = 0; it < 26; it++) {
            char cc = char(int('A') + it);
            string euy = str;
            euy.insert(euy.begin() + i, cc);
            if (is_palindrome(euy)) {
                if (ans.empty()) {
                    ans = euy;
                } else {
                    ans = min(ans, euy);
                }
            }
        }
    }
    if (ans.empty()) {
        ans = "-1";
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int T = 1; T <= tc; T++) {
        cout << "Case #" << T << ": ";
        solve();
    }
    
    return 0;
}