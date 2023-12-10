#include <bits/stdc++.h>

using namespace std;

bool checkSubstring(string s, string t) {
    int n = s.length();
    int m = t.length();
    for (int i = 0; i + m - 1 < n; i++) {
        bool isSame = true;
        for (int j = 0; j < m; j++) {
            if (s[i + j] != t[j]) {
                isSame = false;
                break;
            }
        }
        if (isSame) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    int len = (int) t.size();
    while (checkSubstring(s, t)) {
        s.erase(s.find(t), len);
    }
    cout << s << '\n';
    
    return 0;
}