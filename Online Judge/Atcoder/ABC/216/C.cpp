#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    long long x;
    cin >> x;
    string ans = "";
    while (x > 0) {
        if (x & 1) {
            x--;
            ans += "A";
        } else {
            x /= 2;
            ans += "B";
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
    
    return 0;
}