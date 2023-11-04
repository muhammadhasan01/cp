#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        long long ans = a[x] * a[y] * a[z];
        cout << ans << '\n';
    }
    
    return 0;
}