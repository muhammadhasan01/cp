#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    map<int, int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s[x]++;
    }
    int ans = 0;
    for (auto& [_, c] : s) {
        if (c == 1) {
            ans++;
        }
    }
    cout << ans << '\n';

    return 0;
}