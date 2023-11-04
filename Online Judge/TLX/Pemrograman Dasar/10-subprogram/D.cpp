#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    for (char cc : s) {
        if (isupper(cc)) {
            cc = tolower(cc);
        } else if (islower(cc)) {
            cc = toupper(cc);
        }
        cout << cc;
    }
    cout << '\n';
    
    return 0;
}