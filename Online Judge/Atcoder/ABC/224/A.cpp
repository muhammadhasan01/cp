#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    if (s.substr(0, 2) == "re") {
        cout << "er" << '\n';
    } else {
        cout << "ist" << '\n';
    }
    
    return 0;
}