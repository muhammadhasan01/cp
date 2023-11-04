#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<string> s(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    string p;
    cin >> p;
    for (char cc : p) {
        int num = cc - '1';
        cout << s[num];
    }
    cout << '\n';
    
    return 0;
}