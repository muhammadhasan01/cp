#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int lst = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == 'A') {
            for (int j = i; j < lst; j++) {
                if (s[j] == 'A' && s[j + 1] == 'B') {
                    ++ans;
                    swap(s[j], s[j + 1]);
                } else {
                    break;
                }
            }
            lst = i;
        }
    }
    cout << ans << '\n';
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    
    return 0;
}