#include <bits/stdc++.h>

using namespace std;

const string X = "certainly";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int) s.length();
    int m = (int) X.size();
    int ans = 0;
    for (int i = 0; i + m - 1 <= n; i++) {
        if (s.substr(i, m) == X) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}