#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    char maxi = s[0];
    for (char cc : s) {
        maxi = max(maxi, cc);
    }
    int num = maxi - '0';
    int ans = 0;
    while (num > 0) {
        num = num / 2;
        ans++;
    }
    cout << ans << '\n';
    
    return 0;
}