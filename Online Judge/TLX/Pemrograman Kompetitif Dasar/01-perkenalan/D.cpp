#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, p;
    cin >> s >> p;
    int n = s.length();
    int m = p.length();
    if (m != n - 1) {
        cout << "Wah, tidak bisa :(" << '\n';
    } else {
        int pref = -1;
        int suff = m + 1;
        for (int i = 0; i < m; i++) {
            if (s[i] == p[i]) {
                pref = i;
                continue;
            }
            break;
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; i--, j--) {
            if (s[j] == p[i]) {
                suff = j;
                continue;
            }
            break;
        }
        cout << (suff - pref <= 2 ? "Tentu saja bisa!" : "Wah, tidak bisa :(") << '\n';
    }
    
    return 0;
}