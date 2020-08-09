#include <bits/stdc++.h>

using namespace std;

string s;

bool check(const string& s) {
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        string cur = s;
        for (int it = 0; it < 26; it++) {
            cur[i] = char(int('a') + it);
            if (cur[i] == s[i]) continue;
            if (check(cur)) {
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");

    return 0;
}