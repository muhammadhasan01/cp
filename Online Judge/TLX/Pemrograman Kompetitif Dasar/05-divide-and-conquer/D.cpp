#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
    }
    int q;
    cin >> q;
    while (q--) {
        int y;
        cin >> y;
        int l = 1, r = n, at = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (x[mid] >= y) {
                r = mid - 1;
                at = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << at << '\n';
    }
    
    return 0;
}