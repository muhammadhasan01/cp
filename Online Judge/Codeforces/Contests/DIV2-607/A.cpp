#include <bits/stdc++.h>

using namespace std;

int tc;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> s;
        reverse(s.begin(), s.end());
        int len = s.size();
        if (s.substr(0, 2) == "op") {
            cout << "FILIPINO" << '\n';
        } else if (len >= 4 && s.substr(0, 4) == "used" || s.substr(0, 4) == "usam") {
            cout << "JAPANESE" << '\n';
        } else if (len >= 5 && s.substr(0, 5) == "adinm") {
            cout << "KOREAN" << '\n';
        }
    }

    return 0;
}
