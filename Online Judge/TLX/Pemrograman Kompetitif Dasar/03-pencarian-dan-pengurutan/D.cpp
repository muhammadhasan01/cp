#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int l = upper_bound(a.begin(), a.end(), x) - a.begin();
        int r = upper_bound(a.begin(), a.end(), y) - a.begin() - 1;
        cout << r - l + 1 << '\n';
    }
    
    return 0;
}