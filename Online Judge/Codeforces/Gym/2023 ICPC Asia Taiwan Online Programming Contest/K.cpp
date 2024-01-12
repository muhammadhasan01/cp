#include <bits/stdc++.h>

using namespace std;

const string KICK = "kick";

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s;
    cin >> s;
    int n = (int) s.length();
    int ans = 0;
    for (int i = 0; i + 3 < n; i++) {
        string cur = s.substr(i, 4);
        if (cur == KICK) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}