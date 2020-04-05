#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int tc;
int n, x;
int a[N];

bool can(int x) {
    
}

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        cin >> n >> x;
        vector<bool> vis(300);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            vis[a[i]] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= 200; i++) {
            if (vis[i]) {
                if (x == 0) ans = i;
                continue;
            }
            x--;
            if (x == 0) ans = i;
        }
        cout << ans << '\n';
    }

    return 0;
}