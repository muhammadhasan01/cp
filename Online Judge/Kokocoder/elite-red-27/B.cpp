#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n, vector<int>(k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> cnt(1 << k);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < k; j++) {
            if (a[i][j] > 0) {
                cur += (1 << j);
            }
        }
        cnt[cur]++;
        for (int mask = 0; mask < (1 << k); mask++) {
            if (cnt[mask] == 0) {
                continue;
            }
            bool take = true;
            for (int j = 0; j < k; j++) {
                if (a[i][j] > 0 && mask & (1 << j)) {
                    take = false;
                    break;
                }
            }
            if (take) {
                cout << "YES" << '\n';
                return 0;
            }
        }
    }
    cout << "NO" << '\n';
    
    return 0;
}