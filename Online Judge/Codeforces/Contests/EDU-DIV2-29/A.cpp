#include <bits/stdc++.h>

using namespace std;

string s;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;
    while (1) {
        if (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.front() == '0') s.erase(s.begin());
        if (!s.empty() && s.back() != '0' && s.front() != '0') break;
        if (s.empty()) break;
    }
    bool flag = true;
    int n = s.length();
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        if (s[i] != s[j]) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << '\n';

    return 0;
}