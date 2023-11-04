#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    vector<bool> vis(N);
    int st = m;
    for (int i = st; i < N; i += p) {
        vis[i] = true;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) {
            ++ans;
        }
    }
    cout << ans << '\n';
    
    return 0;
}