#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, x;
    cin >> n >> x;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        if (s <= x) {
            ans += s;
        }
    }
    cout << ans << '\n';
    
    return 0;
}