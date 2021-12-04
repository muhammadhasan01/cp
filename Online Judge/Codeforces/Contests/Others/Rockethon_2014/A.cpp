#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.length();
    char cur = s[0];
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cur == s[i]) {
            cnt++;
        } else {
            if (cnt % 2 == 0) {
                ++ans;
            }
            cnt = 1;
            cur = s[i];
        }
    }
    if (cnt % 2 == 0) {
        ++ans;
    }
    cout << ans << '\n';
    
    return 0;
}