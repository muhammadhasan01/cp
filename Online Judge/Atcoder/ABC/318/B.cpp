#include <bits/stdc++.h>

using namespace std;

const int N = 2e2 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> cnt(N, vector<int>(N));
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int x = a + 1; x <= b; x++) {
            for (int y = c + 1; y <= d; y++) {
                cnt[x][y]++;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cnt[i][j] >= 1) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    
    return 0;
}