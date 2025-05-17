#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> pos(n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        pos[x].emplace_back(i);
    }
    int ans = 0;
    for (int c = 1; c <= n; c++) {
        int l = pos[c][0];
        int r = pos[c][1];
        if (r - l == 2) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}