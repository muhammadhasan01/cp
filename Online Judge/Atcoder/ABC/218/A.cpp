#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    cout << (s[n - 1] == 'o' ? "Yes" : "No") << '\n';
    
    return 0;
}