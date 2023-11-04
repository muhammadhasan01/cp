#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 10, m = 10;
    pair<int, int> mini = make_pair(INT_MAX, INT_MAX);
    pair<int, int> maxi = make_pair(0, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char cc;
            cin >> cc;
            if (cc == '#') {
                pair<int, int> cur = make_pair(i, j);
                mini = min(mini, cur);
                maxi = max(maxi, cur);    
            }
        }
    }
    cout << mini.first << ' ' << maxi.first << '\n';
    cout << mini.second << ' ' << maxi.second << '\n';
    
    return 0;
}