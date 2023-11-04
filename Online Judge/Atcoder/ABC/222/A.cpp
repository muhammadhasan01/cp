#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    while ((int) s.size() < 4) {
        s = "0" + s;
    }
    cout << s << '\n';
    
    return 0;
}