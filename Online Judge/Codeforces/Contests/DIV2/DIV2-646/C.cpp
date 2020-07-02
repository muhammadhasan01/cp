#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int tc;
int deg[N];
int n, x;

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        for (int i = 1; i <= n; i++) deg[i] = 0;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        if (deg[x] <= 1) {
            cout << "Ayush" << '\n';
        } else {
            int sz = n - 3;
            cout << (sz % 2 == 1 ? "Ayush" : "Ashish") << '\n';
        }
    }

    return 0;
}