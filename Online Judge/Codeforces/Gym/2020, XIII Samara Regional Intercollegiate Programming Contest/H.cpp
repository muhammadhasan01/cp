#include <bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        deg[u]++, deg[v]++;
    }
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) ++ans;
    }
    cout << (ans + 1) / 2 << '\n';

    return 0;
}