#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << "Yes" << '\n';
        return 0;
    }
    int n = s.length();
    for (int i = 0; i + 1 < n; i++) {
        swap(s[i], s[i + 1]);
        if (s == t) {
            cout << "Yes" << '\n';
            return 0;
        }
        swap(s[i], s[i + 1]);
    }
    cout << "No" << '\n';
    
    return 0;
}