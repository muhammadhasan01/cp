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
        int n = s.length();
        cout << s.substr(0, 2);
        for (int i = 3; i < n; i += 2) {
            cout << s[i];
        }
        cout << '\n';
    }

    return 0;
}