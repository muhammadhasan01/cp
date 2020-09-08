#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, t;
    cin >> n >> t;
    vector<int> p(n);
    for (int i = 0; i < n - 1; i++) 
        cin >> p[i];
    vector<bool> vis(n);
    int cur = 1;
    while (1) {
        vis[cur - 1] = 1;
        if (cur >= n) break;
        cur += p[cur - 1];
    }
    cout << (vis[t - 1] ? "YES" : "NO") << '\n';

    return 0;
}