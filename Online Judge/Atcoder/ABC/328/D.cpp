#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    vector<char> v;
    for (int i = 0; i < n; i++) {
        int len = (int) v.size();
        if (s[i] == 'C' && len >= 2 && v[len - 1] == 'B' && v[len - 2] == 'A') {
            v.pop_back();
            v.pop_back();
        } else {
            v.emplace_back(s[i]);
        }
    }
    for (char cc : v) {
        cout << cc;
    }
    cout << '\n';
    
    return 0;
}