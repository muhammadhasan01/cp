#include <bits/stdc++.h>
using namespace std;

string s, t;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;
    int kali = 1;
    if (t == "kiri") {
        kali = -kali;
    }
    for (int i = 0; i < (int) s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    int x;
    cin >> x;
    x %= 26;
    vector<char> v(30);
    for (int i = 0; i < 26; i++) {
        v[i] = char(int('a') + i);
    }
    vector<char> k(30);
    for (int i = 0; i < 26; i++) {
        int j = ((i + kali * x) % 26 + 26) % 26;
        k[i] = v[j];
    }
    for (int i = 0; i < (int) s.length(); i++) {
        s[i] = k[s[i] - 'a'];
    }
    cout << s << '\n';

    return 0;
}
