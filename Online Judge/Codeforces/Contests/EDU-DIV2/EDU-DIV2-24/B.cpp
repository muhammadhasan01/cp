#include <bits/stdc++.h>

using namespace std;

const int N = 1e2 + 5;

int n, m;
int a[N], pos[N];

int main() { 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i < m; i++) {
        int cur = a[i + 1] - a[i];
        if (cur <= 0) cur += n;
        if (pos[a[i]] > 0 && pos[a[i]] != cur) {
            cout << -1 << '\n';
            return 0;
        } else if (pos[a[i]] == 0 && vis[cur]) {
            cout << -1 << '\n';
            return 0;
        }
        vis[cur] = 1;
        pos[a[i]] = cur;
    }
    int now = 1;
    for (int i = 1; i <= n; i++) {
        if (pos[i]) continue;
        while (vis[now]) ++now;
        vis[now] = 1;
        pos[i] = now;   
    }
    for (int i = 1; i <= n; i++) {
        cout << pos[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}