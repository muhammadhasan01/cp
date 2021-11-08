#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    auto is_palindrome = [&](string& x) {
        int m = x.size();
        for (int i = 0; i < m; i++) {
            int j = m - i - 1;
            if (i > j) {
                break;
            }
            if (x[i] != x[j]) {
                return false;
            }
        }
        return true;
    };
    for (int i = 0; i < n - 1; i++) {
        string pre = s.substr(0, i + 1);
        string suf = s.substr(i + 1);
        if (is_palindrome(pre) && is_palindrome(suf)) {
            cout << pre << " " << suf << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    
    return 0;
}