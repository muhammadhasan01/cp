#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    bool loggedOut = true;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "login") {
            loggedOut = false;
        } else if (s == "logout") {
            loggedOut = true;
        } else if (s == "private") {
            ans += loggedOut;
        }
    }
    cout << ans << '\n';
    
    return 0;
}