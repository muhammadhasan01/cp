#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int Y = s.back() - '0';
    s.pop_back();
    s.pop_back();
    if (0 <= Y && Y <= 2) {
        cout << s << "-" << '\n';
    } else if (3 <= Y && Y <= 6) {
        cout << s << '\n';
    } else if (7 <= Y && Y <= 9) {
        cout << s << "+" << '\n';
    }
    
    return 0;
}