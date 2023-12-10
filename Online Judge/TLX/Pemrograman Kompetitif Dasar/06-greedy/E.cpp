#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        while (j + 1 < m && b[j] < a[i]) {
            ++j;
        }
        if (b[j] < a[i]) {
            break;
        }
        if (b[j] - a[i] > 1) {
            continue;
        }
        ++ans;
        ++j;
    }
    cout << ans << '\n';
    
    return 0;
}