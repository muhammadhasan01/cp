#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        cout << s[i] << " \n"[i == n - 1];
    }
    
    return 0;
}