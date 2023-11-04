#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> deg(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    int target = n - 1;
    for (int u = 1; u <= n; u++) {
        if (deg[u] == target) {
            cout << "Yes" << '\n';
            return 0;
        }
    }
    cout << "No" << '\n';
    
    return 0;
}