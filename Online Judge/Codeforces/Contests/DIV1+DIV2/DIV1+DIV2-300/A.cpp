#include <bits/stdc++.h>

using namespace std;

const string CF = "CODEFORCES";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    int n = str.size();
    int m = CF.size();
    if (n < m) {
        cout << "NO" << '\n';
        return 0;
    }
    for (int len = 0; len <= m; len++) {
        string res = "";
        for (int i = 0; i < len; i++) {
            res += str[i];
        }
        int suf = m - len;
        for (int i = n - suf; i < n; i++) {
            res += str[i];
        }
        if (res == CF) {
            cout << "YES" << '\n';
            return 0;
        }
    }
    cout << "NO" << '\n';
    
    return 0;
}