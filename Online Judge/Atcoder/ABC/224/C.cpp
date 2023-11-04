#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                long long dx1 = x[j] - x[i];
                long long dy1 = y[j] - y[i];
                long long dx2 = x[k] - x[i];
                long long dy2 = y[k] - y[i];
                if (dy1 * dx2 == dy2 * dx1) {
                    continue;
                }
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}