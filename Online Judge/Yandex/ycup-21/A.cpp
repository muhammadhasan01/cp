#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    cin >> s >> t;
    auto convert = [&](string x) -> string {
        string ret = "";
        int len = x.length();
        for (int i = 0; i < len; i++) {
            if (x[i] == 'o') {
                ret += '1';
                i += 2;
            } else if (x[i] == 'z') {
                ret += '0';
                i += 3;
            }
        }
        return ret;
    };
    auto compare = [&](string x, string y) -> char {
        if (x == y) {
            return '=';
        }
        int n = x.length();
        int m = y.length();
        if (n > m) {
            return '>';
        }
        if (n < m) {
            return '<';
        }
        if (x > y) {
            return '>';
        }
        if (x < y) {
            return '<';
        }
    };
    cout << compare(convert(s), convert(t)) << '\n';
    
    return 0;
}