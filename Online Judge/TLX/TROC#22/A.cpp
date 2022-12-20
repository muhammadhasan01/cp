#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string str;
    cin >> str;
    for (char cc : str) {
        if (cc == '0') {
            cout << "YES" << "\n";
            return 0;
        }
    }
    cout << "NO" << '\n';
    
    return 0;
}