#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    getline(cin, s);
    int k;
    cin >> k;
    bool ok = true;
    if (k < 0) {
        k *= -1;
        k %= 26;
        ok = false;
    }

    vector<int> u(30);
    vector<char> a(30), A(30);
    for (int i = 0; i < 26; i++) {
        u[i] = ((i + (ok ? 1 : -1) * k) % 26 + 26) % 26;
        a[i] = char('a' + u[i]);
        A[i] = char('A' + u[i]);
    }

    int n = s.length();
    for (int i = 0; i < n; i++) {
        if ('a' <= s[i] && s[i] <= 'z') {
            s[i] = a[s[i] - 'a'];
        } else if ('A' <= s[i] && s[i] <= 'Z') {
            s[i] = A[s[i] - 'A'];
        }
    }
    cout << s << '\n';

    return 0;
}
