#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int tc;
int n, p[2 * N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n;
        vector<bool> vis(n + 1);
        vector<int> ans;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> p[i];
            if (vis[p[i]]) continue;
            vis[p[i]] = 1;
            ans.emplace_back(p[i]);
        }
        assert((int) ans.size() == n);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}