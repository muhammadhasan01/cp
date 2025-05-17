#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lst = 0;
    vector<bool> vis(m + 1);
    int uniq = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[a[i]]) {
            vis[a[i]] = true;
            uniq++;
        }
        if (uniq == m) {
            break;
        }
        lst = i;
    }
    cout << n - lst << '\n';
    
    return 0;
}