#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    map<char, char> f, g;
    {
        string X;
        cin >> X;
        char cur = 'a';
        for (int i = 0; i < 26; i++, cur++) {
            f[X[i]] = cur;
            g[cur] = X[i];
        }
    }
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (char& cc : s[i]) {
            cc = f[cc];
        }
    }
    sort(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        for (char& cc : s[i]) {
            cc = g[cc];
        }
        cout << s[i] << '\n';
    }

    return 0;
}